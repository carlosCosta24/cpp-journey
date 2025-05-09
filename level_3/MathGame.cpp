#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

enum enGameLevels
{
    easy = 1,
    medium = 2,
    hard = 3,
    mix = 4,
};
enum enOperation
{
    Add = 1,
    Sub = 2,
    Mult = 3,
    Div = 4,
    Mix = 5,
};
int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}
string GetOperationSym(enOperation Operation)
{
    switch (Operation)
    {
    case enOperation::Add:
        return "+";
    case enOperation::Sub:
        return "-";
    case enOperation::Mult:
        return "*";
    case enOperation::Div:
        return "/";
    case enOperation::Mix:
        return "+";
    default:
        return "+";
    }
}
string GetQuestionLevelString(enGameLevels Level)
{
    string Operations[4] = {"easy", "medium", "hard", "mix"};

    return Operations[Level - 1];
}
enOperation GetRandomOperation()
{
    return (enOperation)RandomNumber(1, 4);
}
void SetTextColor(bool Answer, string Message)
{
    if (Answer)
        cout << "\e[32m" << Message << "! \e[0m" << endl;
    else
        cout << "\e[31m" << Message << "! \e[0m" << endl;
}
int ResultCalculator(int First, int Second, enOperation Operation)
{
    int Result;
    switch (Operation)
    {
    case enOperation::Add:
        Result = First + Second;
        return Result;
    case enOperation::Sub:
        Result = First - Second;
        return Result;
    case enOperation::Mult:
        Result = First * Second;
        return Result;
    case enOperation::Div:
        (Second != 0) ? (Result = First / Second) : 0;
        return Result;
    default:
        return First + Second;
    }
}
struct stQuestion
{
    short FirstNumber = 0;
    short SecondNumber = 0;
    enOperation Operation;
    enGameLevels Level;
    short CorrectAnswer = 0;
    short PlayAnswer = 0;
    bool AnswerResult = false;
};
struct stGameInfo
{
    stQuestion QuestionList[100];
    short NumberOfQuestions;
    enGameLevels QuestionsLevel;
    enOperation OperationType;
    short RightAnswer = 0;
    short WrongAnswer = 0;
    bool Pass = false;
};
stQuestion QuestionGenerator(enGameLevels Level, enOperation Operation)
{
    stQuestion Question;

    if (Level == enGameLevels::mix)
        Level = (enGameLevels)RandomNumber(1, 3);

    if (Operation == enOperation::Mix)
        Operation = GetRandomOperation();

    Question.Operation = Operation;

    switch (Level)
    {
    case enGameLevels::easy:
        Question.FirstNumber = RandomNumber(1, 10);
        Question.SecondNumber = RandomNumber(1, 10);
        break;
    case enGameLevels::medium:
        Question.FirstNumber = RandomNumber(10, 50);
        Question.SecondNumber = RandomNumber(10, 50);
        break;
    case enGameLevels::hard:
        Question.FirstNumber = RandomNumber(50, 100);
        Question.SecondNumber = RandomNumber(50, 100);
        break;
    default:
        Question.FirstNumber = RandomNumber(1, 10);
        Question.SecondNumber = RandomNumber(1, 10);
        break;
    }
    Question.CorrectAnswer = ResultCalculator(Question.FirstNumber, Question.SecondNumber, Question.Operation);
    Question.Level = Level;

    return Question;
}
void AskAndFeedBack(stGameInfo &Info)
{

    for (short NumberOfQuestion = 0; NumberOfQuestion < Info.NumberOfQuestions; NumberOfQuestion++)
    {
        cout << "Question [" << NumberOfQuestion + 1 << " / " << Info.NumberOfQuestions << "]" << endl;
        cout << Info.QuestionList[NumberOfQuestion].FirstNumber << " "
             << GetOperationSym(Info.QuestionList[NumberOfQuestion].Operation) << " "
             << Info.QuestionList[NumberOfQuestion].SecondNumber << " = ";

        cin >> Info.QuestionList[NumberOfQuestion].PlayAnswer;

        if (Info.QuestionList[NumberOfQuestion].PlayAnswer == Info.QuestionList[NumberOfQuestion].CorrectAnswer)
        {
            SetTextColor(true, "Correct answer");
            Info.RightAnswer++;
        }
        else
        {
            SetTextColor(false, "Wrong answer");
            Info.WrongAnswer++;
        }
    }

    Info.Pass = (Info.RightAnswer >= Info.WrongAnswer);
}
void Play(int NumberOfQuestions)
{

    stGameInfo Info;
    Info.NumberOfQuestions = NumberOfQuestions;
    Info.QuestionsLevel = enGameLevels::easy;
    Info.OperationType = enOperation::Mix;

    for (short Question = 0; Question < Info.NumberOfQuestions; Question++)
    {
        Info.QuestionList[Question] = QuestionGenerator(Info.QuestionsLevel, Info.OperationType);
    }

    AskAndFeedBack(Info);

    cout << "Quiz completed!\nRight answers: " << Info.RightAnswer
         << "\nWrong Answers: " << Info.WrongAnswer << endl;

    Info.Pass ? SetTextColor(true, "You passed") : SetTextColor(false, "You didn't passed");
}
int ReadNumber(string Message)
{
    int Number;
    cout << Message;
    cin >> Number;
    return Number;
}

int main()
{

    srand((unsigned)time(NULL));
    Play(ReadNumber("Enter the Number of Questions: "));
    return 0;
}
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
    add = 1,
    sub = 2,
    mult = 3,
    div = 4,
};
enum enStatus
{
    pass = 1,
    fail = 2,
};
struct stGameInfo
{
    short NumberOfQuestions;
    enGameLevels QuestionsLevel;
    enOperation OperationType;
    short RightAnswer;
    short WrongAnswer;
    enStatus status;
    int Result;
};

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

int QuestionGenerator(int Level)
{
    int First, Second;
    switch (Level)
    {
    case enGameLevels::easy:
        First = RandomNumber(1, 10);
        Second = RandomNumber(1, 10);
        return (First, Second);
    case enGameLevels::medium:
        First = RandomNumber(10, 20);
        Second = RandomNumber(10, 20);
        return (First, Second);
    case enGameLevels::hard:
        First = RandomNumber(50, 80);
        Second = RandomNumber(50, 80);
        return (First, Second);
    case enGameLevels::mix:
        First = RandomNumber(1, 80);
        Second = RandomNumber(1, 80);
        return (First, Second);
    default:
        First = RandomNumber(1, 10);
        Second = RandomNumber(1, 10);
        return (First, Second);
    }
}

void ResultPrinter(stGameInfo Info)
{
    cout << "_____________________" << endl;
    cout << "Final Results is " << Info.status;
    cout << "_____________________" << endl;
    cout << "Number of questions: " << Info.NumberOfQuestions << endl;
    cout << "Questions level: " << Info.QuestionsLevel << endl;
    cout << "Operation type: " << Info.OperationType << endl;
    cout << "Number of right answers: " << Info.RightAnswer << endl;
    cout << "Number og wrong answers: " << Info.WrongAnswer << endl;
    cout << "_________________________" << endl;
}

char OperationSign(enOperation Operation)
{
    switch (Operation)
    {
    case enOperation::add:
        return '+';

    case enOperation::sub:
        return '-';
    case enOperation::mult:
        return '*';
    case enOperation::div:
        return '/';
    default:
        return '+';
    }
}

void QuestionPrinter(int Part, int Total, int Level, enOperation Operation)
{

    int First, Second = QuestionGenerator(Level);
    cout << "Question [" << Part << "/" << Total << "]" << endl;
    cout << First << endl;
    cout << Second << OperationSign(Operation);
}

int ResultCalculator(int First, int Second, char Operation)
{
    int Result;
    switch (Operation)
    {
    case '+':
        Result = First + Second;
        return Result;
    case '-':
        Result = First - Second;
        return Result;
    case '*':
        Result = First * Second;
        return Result;
    case '/':
        Result = First / Second;
        return Result;
    default:
        return 0;
    }
}
int ReadNumber(string Message)
{
    int Number;
    cout << Message;
    cin >> Number;
    return Number;
}
stGameInfo Play(int NumberOfQuestions)
{

    stGameInfo Info;
    short Level, RightCount, WrongCount, Status;
    char Operation;
    int first, second = 0;

    for (int Rounds = 1; Rounds <= NumberOfQuestions; Rounds++)
    {
        Info.QuestionsLevel = (enGameLevels)ReadNumber("Enter Questions Level [1] Easy, [2]Med, [3]Hard, [4]Mix? ");
        cout << endl;
        Info.OperationType = (enOperation)ReadNumber("Enter Operation Type [1] Add, [2]Sub, [3]Mul, [4]Div, [5]Mix? ");
        cout << endl;
        Info.RightAnswer = RightCount;
        Info.WrongAnswer = WrongCount;
        Info.status = (enStatus)Status;
        Info.Result = ReadNumber(" ");
        first, second = QuestionGenerator(Info.QuestionsLevel);
        Operation = OperationSign(Info.OperationType);
        Level = Info.QuestionsLevel;

        if (ResultCalculator(first, second, Operation) == Info.Result)
        {
            RightCount++;
            cout << "Right answer :-)" << endl;
        }
        else
        {
            WrongCount++;
            cout << "The right answer is:" << ResultCalculator(first, second, Operation) << ":-)" << endl;
        }

        if (RightCount >= NumberOfQuestions / 2)
        {
            Status = enStatus::pass;
        }
        else
        {
            Status = enStatus::fail;
        }
        ResultPrinter(Info);
    }
    return Info;
}

void GameStarter()
{
    char PlayAgain = 'Y';
    do
    {
        system("clear");
        stGameInfo Info = Play(3);
        cout << "Game over!";

        cout << "Do you want to play again? Y/N: ";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{

    srand((unsigned)time(NULL));
    GameStarter();
    return 0;
}
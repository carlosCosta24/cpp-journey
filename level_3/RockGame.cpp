#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enGameOptions
{
    rock = 1,
    paper = 2,
    scissors = 3,
};

enum enWinner
{
    computer = 1,
    user = 2,
    draw = 3,
};

struct stRoundInfo
{
    short Round = 0;
    enGameOptions user;
    enGameOptions Computer;
    enWinner Winner;
    string WinnerName = "";
};

struct stGameInfo
{
    short Rounds = 0;
    short UserWining = 0;
    short ComputerWinning = 0;
    short draw = 0;
    enWinner Winner;
    string WinnerName = "";
};

int RandomNumber(int From, int To)
{

    return rand() % (To - From + 1) + From;
}

enGameOptions RandomComputerChoice()
{
    return (enGameOptions)RandomNumber(1, 3);
}

enWinner RoundWinner(stRoundInfo Round)
{
    if (Round.user == Round.Computer)
    {
        return enWinner::draw;
    }

    switch (Round.user)
    {
    case enGameOptions::rock:
        return (Round.Computer == enGameOptions::paper) ? enWinner::computer : enWinner::user;

    case enGameOptions::paper:
        return (Round.Computer == enGameOptions::scissors) ? enWinner::computer : enWinner::user;

    case enGameOptions::scissors:
        return (Round.Computer == enGameOptions::rock) ? enWinner::computer : enWinner::user;
    default:
        return enWinner::draw;
    }
}

enWinner GameWinner(short UserWonTime, short ComputerWonTime)
{
    if (UserWonTime > ComputerWonTime)
        return enWinner::user;
    else if (UserWonTime < ComputerWonTime)
        return enWinner::computer;
    else
        return enWinner::draw;
}

string ChoiceName(enGameOptions Option)
{
    string GameOptions[3] = {"rock", "paper", "scissors"};
    return GameOptions[Option - 1];
}

string WinnerName(enWinner Winner)
{
    string GameWinner[3] = {"user", "computer", "draw"};
    return GameWinner[Winner - 1];
}

enGameOptions ReadUserChoice()
{
    short Choice;
    do
    {
        cout << "Enter Your Choice: [1]:Rock,[2]:Paper[3]:Scissors?";
        cin >> Choice;

    } while (Choice < 1 || Choice > 3);

    return (enGameOptions)Choice;
}

void PrintRoundInfo(stRoundInfo Info)
{

    cout << "______________Round[" << Info.Round + 1 << "]___________" << endl;
    cout << "User Choice: " << ChoiceName(Info.user) << endl;
    cout << "Computer Choice: " << ChoiceName(Info.Computer) << endl;
    cout << "Round Winner: " << Info.WinnerName << endl;
    cout << "_________________________" << endl;
}

stGameInfo PlayGame(short RoundsToPlay)
{
    stRoundInfo Round;
    short UserWonTimes = 0, ComputerWonTime = 0, DrawTime = 0;

    for (short rounds = 0; rounds <= RoundsToPlay - 1; rounds++)
    {
        cout << "Round [" << Round.Round + 1 << "] begins: " << endl;
        Round.Round = rounds;
        Round.user = ReadUserChoice();
        Round.Computer = RandomComputerChoice();
        Round.Winner = RoundWinner(Round);
        Round.WinnerName = WinnerName(Round.Winner);

        if (Round.Winner == enWinner::user)
            UserWonTimes++;
        else if (Round.Winner == enWinner::computer)
            ComputerWonTime++;
        else
            DrawTime++;

        PrintRoundInfo(Round);
    }
    return {
        RoundsToPlay, UserWonTimes, ComputerWonTime, DrawTime,
        GameWinner(UserWonTimes, ComputerWonTime),
        WinnerName(GameWinner(UserWonTimes, ComputerWonTime))};
}

void GameStarter()
{
    char PlayAgain = 'Y';

    do
    {
        system("clear");
        stGameInfo Info = PlayGame(3);
        cout << "Game Over! Winner: " << Info.WinnerName << endl;

        cout << "Do you want to play again? (Y/N): ";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
    srand((unsigned)time(NULL));
    GameStarter();
    return 0;
}
/*==========================================================================================================+
 |~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-بسم الله الرحمن الرحیم-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~|
 |~-~-~-و تو ناتانائیل، به کسی مانند خواهی بود که برای هدایت خویش در پی نوری می‌رود که خود به دست دارد-~-~-~|
 |AND SO, NATHANIEL, YOU ARE LIKE THE MAN WHO SHOULD FOLLOW AS HIS GUIDE THE LIGHT HE HOLDS IN HIS OWN HAND.|
 |~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~2048 SIMPLE GAME~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~|
 |~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-AUTHOR: ⲶHSAN~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~|
 |~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-CREATED WITH LOTS OF LOVE!-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~|
 +==========================================================================================================*/
// Libs, headers,includings...
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include "header.h"
#include <windows.h>
#include <mmsystem.h>
using namespace std;
// Globals (:
int n;
int number_of_zeros = 0;
int stat = 0;
int moves = 0;
int input;
string name;
int score;
// Color ANSI codes
const string red("\033[0;31m");
const string boarder_color("\u001b[38;5;105m");
const string nice_purple("\u001b[38;5;69m");
const string green("\033[1;32m");
const string yellow("\033[1;33m");
const string cyan("\033[0;36m");
const string magenta = "\033[0;35m";
const string reset("\033[0m");
// Functions
void print(int **po)
{
    system("cls");
    // Header of game
    cout << nice_purple << "Sᴄᴏʀᴇ: " << reset << score << nice_purple << " ᴍᴏᴠᴇs: " << reset << moves << endl;
    for (int i = 0; i < n; i++)
    {
        for (int h = 0; h < n; h++)
            cout << boarder_color << "┌──────┐ " << reset;
        cout << endl;
        for (int j = 0; j < n; j++)
        {
            // Padding based on count of number's digits
            string temp = to_string(po[i][j]);
            int padding = (6 - temp.size()) / 2;
            cout << boarder_color << "│" << reset;
            for (int j = 1; j <= padding; j++)
            {
                cout << " ";
            }
            // Choose the number color
            switch (po[i][j])
            {
            case 16:
                cout << "\u001b[38;5;178m" << po[i][j] << reset;
                break;
            case 32:
                cout << "\u001b[38;5;214m" << po[i][j] << reset;
                break;
            case 64:
                cout << "\u001b[38;5;220m" << po[i][j] << reset;
                break;
            case 128:
                cout << "\u001b[38;5;221m" << po[i][j] << reset;
                break;
            case 256:
                cout << "\u001b[38;5;208m" << po[i][j] << reset;
                break;
            case 512:
                cout << "\u001b[38;5;209m" << po[i][j] << reset;
                break;
            case 1028:
                cout << "\u001b[38;5;214m" << po[i][j] << reset;
                break;
            case 2048:
                cout << "\u001b[38;5;196m" << po[i][j] << reset;
                break;
            default:
                cout << po[i][j];
                break;
            }
            for (int h = (6 - padding - temp.size()); h > 0; h--)
            {
                cout << " ";
            }
            cout << boarder_color << "│ " << reset;
        }
        cout << "\n";
        for (int h = 0; h < n; h++)
            cout << boarder_color << "└──────┘ " << reset;
        cout << "\n";
    }
    // Footer
    cout << nice_purple << "[Q]: Quit" << reset;
}
// First 2 rand numbers to begin the game
void initialRand(int **po)
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int a = rand() % n;
    srand(static_cast<unsigned int>(time(nullptr) + 777));
    int b = rand() % n;
    srand(static_cast<unsigned int>(time(nullptr) + 787));
    int c = rand() % 4;
    srand(static_cast<unsigned int>(time(nullptr) + 987));
    int a2 = rand() % n;
    srand(static_cast<unsigned int>(time(nullptr) + 1457));
    int b2 = rand() % n;
    srand(static_cast<unsigned int>(time(nullptr) + 798));
    int c2 = rand() % 4;
    // cout<<"a is "<<a<<"and b is: "<<b<<" c: "<<c;
    if (c == 3)
        po[a][b] = 4;
    else
        po[a][b] = 2;
    if (c2 == 3)
        po[a2][b2] = 4;
    else
        po[a2][b2] = 2;
}
// This s*** returns 1 for continue,2 for game-over and 3 for win
int status(int **p)
{
    score = 0;
    number_of_zeros = 0;
    bool gameover = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (p[i][j] == 0)
            {
                gameover = false;
                number_of_zeros++;
            }
            if (p[i][j] == 2048)
            {
                return 3;
            }
            if (i > 0 && p[i - 1][j] == p[i][j])
            {
                gameover = false;
            }
            if (j > 0 && p[i][j - 1] == p[i][j])
            {
                gameover = false;
            }
            if (p[i][j] > score)
                score = p[i][j];
        }
    }
    if (gameover == false)
        return 1;
    return 2;
}
// Generating rand in the middle of game
void midGameRand(int **p)
{
    int counter = 0;
    int x[number_of_zeros][2];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (p[i][j] == 0)
            {
                x[counter][0] = i;
                x[counter][1] = j;
                counter++;
            }
        }
    }
    srand(static_cast<unsigned int>(time(nullptr) + 999));
    int a = rand() % number_of_zeros;
    int b = rand() % 4;
    // The chance of 2 is 2 times more than 4(3x)
    if (b == 3)
        p[x[a][0]][x[a][1]] = 4;
    else
        p[x[a][0]][x[a][1]] = 2;
}
void leftward(int **p)
{
    int zeros = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (p[i][j] == 0)
            {
                zeros++;
                continue;
            }
            else if (zeros != 0 && (j - zeros - 1 < 0 || p[i][j - zeros - 1] != p[i][j]))
            {
                p[i][j - zeros] = p[i][j];
                p[i][j] = 0;
            }
            else if (zeros != 0 && (j - zeros - 1 >= 0 && p[i][j - zeros - 1] == p[i][j]))
            {
                p[i][j - zeros - 1] *= 2;
                p[i][j] = 0;
                zeros++;
            }
            else if (zeros == 0)
            {
                if (j - 1 >= 0 && p[i][j] == p[i][j - 1])
                {
                    p[i][j - 1] *= 2;
                    p[i][j] = 0;
                    zeros++;
                }
            }
        }
        zeros = 0;
    }
}
void rightward(int **p)
{
    int zeros = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (p[i][j] == 0)
            {
                ++zeros;

                continue;
            }

            else if (zeros != 0)
            {
                if (j + zeros + 1 >= n || p[i][j + zeros + 1] != p[i][j])
                {
                    p[i][j + zeros] = p[i][j];
                    p[i][j] = 0;
                }
                else
                {
                    p[i][j + zeros + 1] *= 2;
                    p[i][j] = 0;
                    ++zeros;
                }
            }
            else
            {
                if (j + 1 < n && p[i][j] == p[i][j + 1])
                {
                    p[i][j + 1] *= 2;
                    p[i][j] = 0;
                    ++zeros;
                }
            }
        }
        zeros = 0;
    }
}
void upward(int **p)
{
    int zeros = 0;
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (p[i][j] == 0)
            {
                ++zeros;
                continue;
            }
            else if (zeros != 0)
            {
                if (i - zeros - 1 < 0 || p[i - zeros - 1][j] != p[i][j])
                {
                    p[i - zeros][j] = p[i][j];
                    p[i][j] = 0;
                }
                else
                {
                    p[i - zeros - 1][j] *= 2;
                    p[i][j] = 0;
                    ++zeros;
                }
            }
            else
            {
                if (i - 1 >= 0 && p[i][j] == p[i - 1][j])
                {
                    p[i - 1][j] *= 2;
                    p[i][j] = 0;
                    ++zeros;
                }
            }
        }
        zeros = 0;
    }
}
void downward(int **p)
{
    int zeros = 0;
    for (int j = 0; j < n; j++)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (p[i][j] == 0)
            {
                ++zeros;
                continue;
            }
            else if (zeros != 0)
            {
                if (i + zeros + 1 >= n || p[i + zeros + 1][j] != p[i][j])
                {
                    p[i + zeros][j] = p[i][j];
                    p[i][j] = 0;
                }
                else
                {
                    p[i + zeros + 1][j] *= 2;
                    p[i][j] = 0;
                    ++zeros;
                }
            }
            else
            {
                if (i + 1 < n && p[i][j] == p[i + 1][j])
                {
                    p[i + 1][j] *= 2;
                    p[i][j] = 0;
                    ++zeros;
                }
            }
        }
        zeros = 0;
    }
}
// Checks if the command was valid(Has any change in the game)
bool checkChange(int **p1, int **p2)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (p1[i][j] != p2[i][j])
                return true;
        }
    return false;
}

int main()
{
    // Disk code
    // Make console UTF-8
    //Might be useful for unix-based machines
    // std::locale::global(std::locale("en_US.utf8"));
    // For windows:
    SetConsoleOutputCP(CP_UTF8);

reset_menu:
    int selection = 0;
    selection = main_menu(1);
    // If user selected exit
    if (selection == 3)
        exit(0);
    // If user selected leaderboard
    if (selection == 2)
    {
        leaderboard();
        // Sorry,... but I had to :-(
        goto reset_menu;
    }
    // If user selected new game
    if (selection == 1)
    {
        cout << "What's your name mate?";
        getline(cin, name);
        system("cls");
        // Tap tap!
        PlaySound(TEXT("data/Tap.wav"), NULL, SND_FILENAME | SND_ASYNC);
        cout << "Eɴᴛᴇʀ ᴅɪᴍᴇɴᴛɪᴏɴs:";
        cin >> n;
        // Adad dorost ro bede dige :|
        while (n < 2)
        {
            cout << "Eɴᴛᴇʀ ᴅɪᴍᴇɴᴛɪᴏɴs:";
            cin >> n;
        }
        int **po = new int *[n];

        for (int i = 0; i < n; i++)
        {
            po[i] = new int[n];
            for (int j = 0; j < n; j++)
                po[i][j] = 0;
        }
        initialRand(po);
        print(po);

        // Here attemping to avoid "کدشر"
        while (input != 'q')
        {

            stat = status(po);
            // continue
            if (stat == 1)
            {
                input = getch();
                int **temp = new int *[n];

                for (int i = 0; i < n; i++)
                {
                    temp[i] = new int[n];
                    for (int j = 0; j < n; j++)
                        temp[i][j] = po[i][j];
                }
                // Check if arrow keys are pressed
                if (input == 224)
                {
                    input = getch();
                    //  Right
                    if (input == 77)
                        input = 'd';
                    // Left
                    else if (input == 75)
                        input = 'a';
                    // Up
                    else if (input == 72)
                        input = 'w';
                    // Down
                    else if (input == 80)
                        input = 's';
                }
                if (input == 'a')
                {
                    PlaySound(TEXT("data/Tap.wav"), NULL, SND_FILENAME | SND_ASYNC);
                    leftward(po);
                    if (checkChange(po, temp))
                    {
                        ++moves;
                        status(po);
                        midGameRand(po);
                    }
                    print(po);
                }
                if (input == 'd')
                {
                    PlaySound(TEXT("data/Tap.wav"), NULL, SND_FILENAME | SND_ASYNC);
                    rightward(po);
                    if (checkChange(po, temp))
                    {
                        ++moves;
                        status(po);
                        midGameRand(po);
                    }
                    print(po);
                }
                if (input == 'w')
                {
                    PlaySound(TEXT("data/Tap.wav"), NULL, SND_FILENAME | SND_ASYNC);
                    upward(po);
                    if (checkChange(po, temp))
                    {
                        ++moves;
                        status(po);
                        midGameRand(po);
                    }
                    print(po);
                }
                if (input == 's')
                {
                    PlaySound(TEXT("data/Tap.wav"), NULL, SND_FILENAME | SND_ASYNC);
                    downward(po);
                    if (checkChange(po, temp))
                    {
                        ++moves;
                        status(po);
                        midGameRand(po);
                    }
                    print(po);
                }
            }
            else
                break;
        }
        // Lost
        if (stat == 2)
        {
            update_leaderboard(name, score, moves);
            PlaySound(TEXT("data/lost.wav"), NULL, SND_FILENAME | SND_ASYNC);
            system("cls");
            cout << "\u001b[38;5;196m";
            cout << "███╗░░██╗░█████╗░░█████╗░██████╗░  ██████╗░██████╗░░█████╗░  ░░██╗██╗░░██╗\n████╗░██║██╔══██╗██╔══██╗██╔══██╗  ██╔══██╗██╔══██╗██╔══██╗  ░██╔╝╚██╗██╔╝\n██╔██╗██║██║░░██║██║░░██║██████╦╝  ██████╦╝██████╔╝██║░░██║  ██╔╝░░╚███╔╝░\n██║╚████║██║░░██║██║░░██║██╔══██╗  ██╔══██╗██╔══██╗██║░░██║  ╚██╗░░██╔██╗░\n██║░╚███║╚█████╔╝╚█████╔╝██████╦╝  ██████╦╝██║░░██║╚█████╔╝  ░╚██╗██╔╝╚██╗\n╚═╝░░╚══╝░╚════╝░░╚════╝░╚═════╝░  ╚═════╝░╚═╝░░╚═╝░╚════╝░  ░░╚═╝╚═╝░░╚═╝\n";
            cout << reset;
            getch();
        }
        // Won
        if (stat == 3)
        {
            update_leaderboard(name, score, moves);
            system("cls");
            PlaySound(TEXT("data/Gravity.wav"), NULL, SND_FILENAME | SND_ASYNC);

            cout << "\u001b[38;5;50m";
            cout << "░██████╗░░██████╗░  ░░░░░░  ░██╗░░░░░░░██╗██████╗░\n██╔════╝░██╔════╝░  ░░░░░░  ░██║░░██╗░░██║██╔══██╗\n██║░░██╗░██║░░██╗░  █████╗  ░╚██╗████╗██╔╝██████╔╝\n██║░░╚██╗██║░░╚██╗  ╚════╝  ░░████╔═████║░██╔═══╝░\n╚██████╔╝╚██████╔╝  ░░░░░░  ░░╚██╔╝░╚██╔╝░██║░░░░░\n░╚═════╝░░╚═════╝░  ░░░░░░  ░░░╚═╝░░░╚═╝░░╚═╝░░░░░\n";
            cout << reset;
            cout << "\n  Celebrate by enjoying Gravity guy once more... (: ♫";
            getch();
        }
    }
}
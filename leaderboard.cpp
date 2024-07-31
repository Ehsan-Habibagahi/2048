#include <iostream>
#include <fstream>
#include <iomanip>
#include "header.h"
#include <conio.h>
#include <string>
#include <iomanip>

using namespace std;
// Print leaderboard
void leaderboard()
{
    struct Player
    {
        string name;
        int score;
        int move;
    };

    fstream fs("data/leaderboard.csv", ios::in);
    int count;
    int counter = 0;
    int counter2 = 0;
    string line, word;
    // check number of data
    fs >> count;
    Player player[count];
    while (getline(fs, line))
    {
        if (counter == 0)
        {
            ++counter;
            continue;
        }
        stringstream ss(line);
        // Seprate data by "," and put in palyers
        while (getline(ss, word, ','))
        {
            if (counter2 == 0)
            {
                player[counter - 1].name = word;
            }
            else if (counter2 == 1)
            {
                player[counter - 1].score = stoi(word);
            }
            else
            {
                player[counter - 1].move = stoi(word);
                counter2 = 0;
                break;
            }
            ++counter2;
        }
        ++counter;
    }
    // Bubble sort
    int i, j;
    bool swapped;
    for (i = 0; i < count - 1; i++)
    {
        swapped = false;
        for (j = 0; j < count - i - 1; j++)
        {
            if (player[j].score > player[j + 1].score)
            {
                swap(player[j], player[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
    system("cls");
    // print
    cout << "█░░ █▀▀ ▄▀█ █▀▄ █▀▀ █▀█ █▄▄ █▀█ ▄▀█ █▀█ █▀▄\n█▄▄ ██▄ █▀█ █▄▀ ██▄ █▀▄ █▄█ █▄█ █▀█ █▀▄ █▄▀\n\n";
    cout << "\u001b[38;5;49m";
    cout << left << setw(30) << "     Nᴀᴍᴇ";
    cout << setw(5) << "          Sᴄᴏʀᴇ";
    cout << setw(10) << "    Mᴏᴠᴇs";
    cout << "\u001b[0m";
    // Rainbow
    for (int i = 0; i < count; i++)
    {
        int color = 160 + i;
        cout << "\u001b[38;5;" << color << "m" << endl;
        cout << "[" << i + 1 << "]. " << left << setw(30) << player[count - 1 - i].name;
        cout << "\u001b[0m";
        cout << setw(10) << player[count - 1 - i].score;
        cout << setw(10) << player[count - 1 - i].move << endl;
    }
    cout << "\u001b[0m";
    cout << "\n[B]: Back";
    for (int i = 0; i < counter; i++)
    {
    }

    fs.close();
    while (true)
    {
        if (getch() == 'b')
        {
            cout << "exit";
            return;
        }
    }
}
// Update leaderboard
void update_leaderboard(string name, int score, int moves)
{
    // Append new data
    fstream fs("data/leaderboard.csv", ios::out | ios::app);
    fs << name << "," << score << "," << moves;
    fs.close();
    // Updating the counter of data saved in file
    ifstream fi("data/leaderboard.csv");
    // Put new data in temp file
    ofstream fo("data/temp.csv");
    string line;
    if (getline(fi, line))
    {
        line = to_string(stoi(line) + 1);
        fo << line << "\n";
    }
    while (getline(fi, line))
    {
        fo << line << endl;
    }
    fo.close();
    fi.close();
    // Remove previous file and rename temp
    remove("data/leaderboard.csv");
    rename("data/temp.csv", "data/leaderboard.csv");
}
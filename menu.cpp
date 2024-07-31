#include <iostream>
#include "header.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>
using namespace std;
// Reset the terminal color
const string reset("\033[0m");

int main_menu(int choice)
{
    system("cls");
    // Mage Ahang nostalgic tar az Gravity Guy vojood dare?! ... Hmm... Lovely! :3
    PlaySound(TEXT("data/Gravity.wav"), NULL, SND_FILENAME | SND_ASYNC);
    int input = -1;
    // Until hasn't pressed enter
    while (input != 13)
    {
        system("cls");
        if (choice == 1)
        {
            cout << "\t"
                 << "██████╗░░█████╗░░░██╗██╗░█████╗░\n\t╚════██╗██╔══██╗░██╔╝██║██╔══██╗\n\t░░███╔═╝██║░░██║██╔╝░██║╚█████╔╝\n\t██╔══╝░░██║░░██║███████║██╔══██╗\n\t███████╗╚█████╔╝╚════██║╚█████╔╝\n\t╚══════╝░╚════╝░░░░░░╚═╝░╚════╝░\n";
            cout << "\u001b[38;5;196m";
            cout << "               ╒══════════════════╕" << endl;

            cout << "             ➤ │";
            cout << "     Nᴇᴡ Gᴀᴍᴇ";
            cout << "     ";
            cout << "│" << endl;
            cout << "               ╘══════════════════╛\n";
            cout<<reset;

            cout << "               ╒══════════════════╕" << endl;

            cout << "               │";
            cout << "    LᴇᴀᴅᴇʀBᴏᴀʀᴅ";
            cout << "   ";
            cout << "│" << endl;
            cout << "               ╘══════════════════╛\n";
            cout << "               ╒══════════════════╕" << endl;

            cout << "               │";
            cout << "       Exɪᴛ";
            cout << "       ";
            cout << "│" << endl;
            cout << "               ╘══════════════════╛\n";
        }
        else if (choice == 2)
        {
            cout << "\t"
                 << "██████╗░░█████╗░░░██╗██╗░█████╗░\n\t╚════██╗██╔══██╗░██╔╝██║██╔══██╗\n\t░░███╔═╝██║░░██║██╔╝░██║╚█████╔╝\n\t██╔══╝░░██║░░██║███████║██╔══██╗\n\t███████╗╚█████╔╝╚════██║╚█████╔╝\n\t╚══════╝░╚════╝░░░░░░╚═╝░╚════╝░\n";
            cout << "               ╒══════════════════╕" << endl;

            cout << "               │";
            cout << "     Nᴇᴡ Gᴀᴍᴇ";
            cout << "     ";
            cout << "│" << endl;
            cout << "               ╘══════════════════╛\n";
            cout << "\u001b[38;5;196m";

            cout << "               ╒══════════════════╕" << endl;

            cout << "             ➤ │";
            cout << "    LᴇᴀᴅᴇʀBᴏᴀʀᴅ";
            cout << "   ";
            cout << "│" << endl;
            cout << "               ╘══════════════════╛\n";
            cout << reset;
            cout << "               ╒══════════════════╕" << endl;

            cout << "               │";
            cout << "       Exɪᴛ";
            cout << "       ";
            cout << "│" << endl;
            cout << "               ╘══════════════════╛\n";
        }
        else if (choice == 3)
        {
            cout << "\t"
                 << "██████╗░░█████╗░░░██╗██╗░█████╗░\n\t╚════██╗██╔══██╗░██╔╝██║██╔══██╗\n\t░░███╔═╝██║░░██║██╔╝░██║╚█████╔╝\n\t██╔══╝░░██║░░██║███████║██╔══██╗\n\t███████╗╚█████╔╝╚════██║╚█████╔╝\n\t╚══════╝░╚════╝░░░░░░╚═╝░╚════╝░\n";
            cout << "               ╒══════════════════╕" << endl;

            cout << "               │";
            cout << "     Nᴇᴡ Gᴀᴍᴇ";
            cout << "     ";
            cout << "│" << endl;
            cout << "               ╘══════════════════╛\n";

            cout << "               ╒══════════════════╕" << endl;

            cout << "               │";
            cout << "    LᴇᴀᴅᴇʀBᴏᴀʀᴅ";
            cout << "   ";
            cout << "│" << endl;
            cout << "               ╘══════════════════╛\n";
            cout << "\u001b[38;5;196m";
            cout << "               ╒══════════════════╕" << endl;

            cout << "             ➤ │";
            cout << "       Exɪᴛ";
            cout << "       ";
            cout << "│" << endl;
            cout << "               ╘══════════════════╛\n";
            cout << reset;
        }
        input = getch();
        // To handle special keys(arrows)
        if (input == 224 || input == 0)
        {
            input = getch();
            if (input == 80)
                ++choice;
            else if (input == 72)
                --choice;

            if (choice == 0)
                choice = 3;
            if (choice == 4)
                choice = 1;
        }
    }
    // Stop song
    if (choice == 1)
        PlaySound(NULL, NULL, 0);
    return choice;
}
#include <iostream>
#include <string>

#include "generic.hpp"
#include "Dungeon.hpp"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int startMenu(Dungeon&);
int gameRun(Dungeon&);
// ---------------- Function to be created
void configMenu()
{ cout << "\nDon not blame me, you can play the game right?\n"; }

int main()
{
    fileRead("Output.txt", "Presentation", "EndPresentation");

    int gState = 0;
    char eName = 'E';
    int rows = 10, cols = 10, traps = 10, enemys = 0;
    while (true)
    {
        Dungeon game;
        // ---------------- Process the menu options
        // ---------------- Game preconfig on the settings section
        gState = startMenu(game);

        // ---------------- The Game
        if (gState == 1){
            gameRun(game);
        } else {
            cout << "Thank you for playing my game.\n"
                 << "Have a good life."
                 << endl;
            return 0;
        }
    }
}

int startMenu(Dungeon& game)
{
    while (true)
    {
        fileRead("Output.txt", "MainMenu", "EndMainMenu");

        int choice = 0;
        cin >> choice;

        if (cin.fail())
        {
            cerr << "This is a terribly invalid input, "
                 << "please try again."
                 << endl;
            cin.clear();
        } else {
            switch (choice)
            {
            case 1:
                cout << "The game will begin now.";
                return 1;
            break;
            case 2:
                fileRead("Output.txt", "Instructions", "EndInstructions");
            break;
            case 3:
            {
                // ---------------- Settings (too much work for now)
                configMenu();
            }
            break;
            case 4:
                return -1;
            break;
            default:
            {
                cerr << choice
                     << " is not a valid choice, please try again."
                     << endl;
            }
            break;
            }
        }
        clearOutput();
    }
}

int gameRun(Dungeon& game){
    game.print();
    while (true)
    {
        int x = 0, y = 0;
        char direction = ' ';

        bool safe = false;
        while(!safe){
            safe = true;

            cout << "Choose a direction to move: ";
            cin >> direction;
            clearOutput();

            switch (direction)
            {
            case 'd':
                x = 1;
            break;
            case 'a':
                x = -1;
            break;
            case 's':
                y = 1;
            break;
            case 'w':
                y = -1;
            break;
            case '0':
                return 0;
            default:
                cerr <<"Not a valid input!\n"
                        <<"Try harder if you want to break my program buddy.\n"
                        <<"Something like \'w\' \'a\' \'s\' or \'d\'."
                        << endl;
                safe = false;
            break;
            }
        }

        int victory = game.movePlayer(y, x);
        if (game.moveEnemys('E') != 0)
        {
            victory = -1;
        }

        if (victory != 0)
        {
            switch (victory)
            {
            case 1:
                cout << "You win! Congrats.";
                break;
            case -1:
                cout << "You lose! Boo! SHAME ON YOU!" << endl;
                break;
            }
            return 0;
        }
        else
        {
            game.print();
        }
    }
}
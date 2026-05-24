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
int configMenu(int&, int&, int&, char&);
int gameRun(Dungeon&, const char&);

int main()
{
    fileRead("Output.txt", "Presentation", "EndPresentation");

    char eName = 'E';
    int size = 10, traps = 10, enemys = 5;
    while (true)
    {
        Dungeon game(size, size, traps);
        game.initEnemys(enemys, eName);
        int gState = startMenu(game);

        switch (gState){
            case 1:
                gameRun(game, eName);
            break;
            case 0:
                configMenu(size, traps, enemys, eName);
            break;
            case -1:
                cout << "Thank you for playing my game.\n"
                    << "Have a good life."
                    << endl;
                return 0;
            break;
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
                return 0;
            }
            break;
            case 4:
                return -1;
            break;
            default:
            {
                fileRead("Output.txt", "ErrorMsg", "EndErrorMsg");
            }
            break;
            }
        }
        clearOutput();
    }
}

int configMenu
    (int& size, int& traps, int& enemys, char& eName){

    while (true){
        fileRead("Output.txt", "ConfigTxt", "EndConfigTxt");

        int choice = 0;
        cin >> choice;

        if (cin.fail()){
            cerr << "Where did you read you should input"
                    << " anything but a number? huh?\n"
                    << "Try again."
                    << endl;
            cin.clear();
            clearOutput();
        } else {
            switch(choice){
                case 1:
                    return 0;
                break;
                case 2:
                {
                    bool safe = false;
                    while(!safe){
                        cout << "\nThe number of traps is limited to you board."
                                << "\nThe current maximun is: " << (size * size) /2
                                << "\nInput the number of traps you want: ";
                        cin >> traps;

                        if (cin.fail()){
                            cerr << "\nYeah. Each option have a different error message."
                                    << "\nCongratulations, you failed on a simple task."
                                    << endl;
                            cin.clear();
                        } else {
                            if( traps > ( ( size * size ) / 2 ) || traps < 0 ){
                                cerr << "\nPlease, could you choose a proper number?"
                                        << endl;
                            } else {
                                safe = true;
                            }
                        }
                        clearOutput();
                    }
                }
                break;
                case 3:
                {
                    bool safe = false;
                    while(!safe){
                        cout << "\nThe number of enemys is limited to you board."
                                << "\nThe current maximun is: " << (size * size)/2
                                << "\nInput the number of enemys you want: ";
                        cin >> enemys;

                        if (cin.fail()){
                            cerr << "\nThere you go. Your error message of the day."
                                    << "\nPlease, use the program properly ;.; ."
                                    << endl;
                            cin.clear();
                        } else {
                            if( enemys > ( ( size * size ) / 2 ) || enemys < 0){
                                cerr << "\nI have TOLD you the range, did I not?"
                                        << "\nDo it right this time."
                                        << endl;
                            } else {
                                safe = true;
                            }
                        }
                        clearOutput();
                    }
                }
                break;
                case 4:
                {
                    bool safe = false;
                    while(!safe){
                        safe = true;
                        int temp = 0;
                        cout << "\nInput a board size ranging from 5 to 35: ";
                        cin >> temp;

                        if (cin.fail()){
                            cerr << "\nEaster egg in the error messages! YAY!" << endl;
                            cin.clear();
                        } else {
                            if(temp >= 5 && temp <= 35){
                                size = temp;
                            } else {
                                fileRead("Output.txt", "ErrorMsg", "EndErrorMsg");
                                safe = false;
                            }
                        }
                        clearOutput();
                    }
                } 
                break;
                case 5:
                {
                    bool safe = false;
                    while(!safe){
                        cout << "\nChoose the enemy tag (you can not use any repeated tag): ";
                        cin >> eName;

                        if (eName == 'P' || eName == 'T' || eName == '.' || eName == 'X'){
                            cerr << "\nYou HAD to choose the only tags"
                                    << "that were NOT available right?"
                                    << "\nWell, try again, troublemaker."
                                    << endl;
                        } else {
                            safe = true;
                        }
                        clearOutput();
                    }
                }
                break;
                case 6:
                    size = 10;
                    traps = 10;
                    enemys = 5;
                    eName = 'E';

                    cout << "\nAll values have been set to default."
                         << "\nSize = " << size
                         << "\nTraps = " << traps
                         << "\nEnemys = " << enemys
                         << "\nEnemys name = " << eName
                         << endl;
                break;
            }
        }
    }    
}

int gameRun(Dungeon& game, const char& eName){
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
                fileRead("Output.txt", "ErrorMsg", "EndErrorMsg");
                cerr <<"Input something like \'w\' \'a\' \'s\' \'d\' or \'0\'."
                     << endl;
                safe = false;
            break;
            }
        }

        int victory = game.movePlayer(y, x);
        if (game.moveEnemys(eName) != 0)
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
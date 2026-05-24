//Make a two player tic tac toe game.

//★ Modify the program so that it will announce when a player
//has won the game (and which player won, x or o)

//★★ Modify the program so that it is a one player game against
//the computer (with the computer making its moves randomly)

#include <iostream>
#include <string>
#include <sstream>
#include "generic.hpp"
#include "Tic_Tac_Toe.hpp"
#include "IA_TTT.hpp"

using std::cout; using std::endl;
using std::cin; using std::string;
using std::cerr;

int main(){
    cout << "Welcome to my Tic Tac Toe game!" << endl;

    TTT game;
    initializer(game);

    bool gEnd = false;
    while (!gEnd){
        bool IA = false, plyr = false;
        cout << "Please, choose your oponent: "
             << "\n1 = human vs IA"
             << "\n2 = human vs human"
             << endl;
        IA = simpleChoice("vs IA", "vs human");

        if (IA){
            cout << "Choose your symbol: "
                 << "\n1 = X (Player 1)"
                 << "\n2 = O (Player 2)"
                 << endl;
            plyr = simpleChoice("X", "O");
        }

        cout << "The game will start."
             << "\nInput numbers ranging from 1 to 9 to choose"
             << "\n a slot or 0 to access the menu."
             << endl;
        
        printBoard(game);

        bool gRestart = false, turn = true, NOTmenu = true;
        int choice = 0;
        while (!gEnd && !gRestart){

            string choiceMsg = turn? "Player 1 (X), make your choice: ":
                "Player 2 (O) make your choice: ";
            cout << choiceMsg;

            if (IA && (turn != plyr)){
                IA_turn(game, turn);
            
            } else {
                bool safe = false;
                while (!safe){
                    cin >> choice;
                    switch (choice){
                        // this is not common code, it is intended to execute the same logic
                        // whith any case from 1 to 9.
                        case 1: case 2: case 3:
                        case 4: case 5: case 6:
                        case 7: case 8: case 9:
                            safe = boardUpdate(game, choice, turn);
                            if (!safe){
                                cerr << choice << " is not a valid slot!";
                            }
                        break;
                        case 0:
                            NOTmenu = false;
                            safe = true;
                        break;
                        default:
                            cerr << choice
                                 << " is not a valid choice!"
                                 << "\nChoose a number ranging from 1 to 9"
                                 << "\n or 0 to access the menu!";
                            choice = 0;
                        break;
                    }
                }
            }

            if (!NOTmenu){
                cout << "You accessed the menu: "
                     << "\n0 to quit;"
                     << "\n1 to restart the current game;"
                     << "\n2 to return to slot choice."
                     << endl;

                bool safe2 = false;
                while (!safe2){
                    cin >> choice;
                    switch (choice){
                        case 0:
                            gEnd = true;
                            safe2 = true;
                        break;
                        case 1:
                            gRestart = true;
                            safe2 = true;
                            initializer(game);
                        break;
                        case 2:
                            safe2 = true;
                        break;
                        default:
                            cerr << choice 
                                 << " is not a valid choice!"
                                 << "\n Choose: "
                                 << "\n 0 = quit;"
                                 << "\n 1 = restart"
                                 << "\n 2 = return"
                                 << endl;
                            choice = 0;
                        break;
                    }
                }
                NOTmenu = true;
            
            } else {
                printBoard(game);
                turn = !turn;
                string winner = winnerCheck(game);
                if (!winner.empty()){
                    if (winner == " Draw"){
                        cout << "It is a" << winner << "!" << endl;
                    } else {
                        winner = (winner == " X")? "Player 1": "Player 2";
                        cout << "Game Over! The winner is: " << winner << endl;
                    }
                    initializer(game);
                    gRestart = true;
                }  
            }
        }
    }

    return 0;
}
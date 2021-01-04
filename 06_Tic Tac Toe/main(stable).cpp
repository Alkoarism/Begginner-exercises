//Make a two player tic tac toe game.

//★ Modify the program so that it will announce when a player
//has won the game (and which player won, x or o)

//★★ Modify the program so that it is a one player game against
//the computer (with the computer making its moves randomly)

#include <iostream>
#include <string>
#include <sstream>
#include "Tic_Tac_Toe.hpp"

using std::cout; using std::endl;
using std::cin; using std::string;
using std::cerr;

int main(){
    cout << "Welcome to my Tic Tac Toe game!"
         << "\nIt is a 2 player game, so please, play with a friend."
         << "\nYou can choose between \"X\" (Player 1) and \"O\" (Player 2)."
         << "\nThe game is turn-based."
         << "\nIn your turn choose a slot by entering its number."
         << "\nRestart with 0;"
         << "\nOr quit with any other input."
         << endl;

    TTT game;
    initializer(game);
    printBoard(game);

    int choice = 0;
    bool turn = true;
    string winner;
    while ((choice >= 0) && (choice < 10)){
        if (turn){
            cout << "Player 1 (X) make your choice: ";
        } else {
            cout << "Player 2 (O) make your choice: ";
        }
        cin >> choice;

        if (choice == 0){
            gameReset(game);
        } else if ((choice > 0) && (choice < 10)){
            boardUpdate(game, choice, turn);
        }
        turn = !turn;

        winner = winnerCheck(game);
        if (!winner.empty()){
            if (winner == " Draw"){
                cout << "It is a" << winner << "!" << endl;
            } else {
                cout << "Congratulations! The winner is:" << winner << endl;
            }
            gameReset(game);
        }
    }

    return 0;
}
#include "Dungeon.hpp"
#include <iostream>

using std::cin; using std::cout;
using std::endl;

int main(){
    cout << "Seventh run- Still making the game playable.\n";

    double ver = 0.6;
    int enemys = 0;

    cout << "Welcome to my take on the"
         << " dungeon crawler exercise game.\n"
         << " ver.:" << ver
         << endl;

    Dungeon board;

    //enemy function testing
    cin >> enemys;
    board.initTraps(enemys);
    board.print();
    
    //temporary game loop test
    while(true){
        int x = 0, y = 0;
        char direction = ' ';
        cin >> direction;

        switch (direction){
            case 'w':
                y = 1;
                break;
            case 'a':
                y = -1;
                break;
            case 's':
                x = -1;
                break;
            case 'd':
                x = 1;
                break;
        }
        int victory = board.movePlayer(x,y);

        if (victory != 0){
            switch (victory){
                case 1:
                    cout << "You win!";
                break;
                case -1:
                    cout << "You lose!";
                break;
            }
            return 0;
        }

        board.print();
    }
}
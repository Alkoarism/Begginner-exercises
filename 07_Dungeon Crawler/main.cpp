#include "Dungeon.hpp"
#include <iostream>

using std::cin; using std::cout;
using std::endl;

int main(){
    cout << "Eigth run- Now adding moving enemys!.\n";

    double ver = 0.7;
    int enemys = 0;

    cout << "Welcome to my take on the"
         << " dungeon crawler exercise game.\n"
         << "ver.:" << ver
         << endl;

    Dungeon board;

    //enemy function testing
    board.initEnemys(5, 'E');
    board.print();
    
    //temporary game loop test
    while(true){
        int x = 0, y = 0;
        char direction = ' ';
        cin >> direction;

        switch (direction){
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
        }
        int victory = board.movePlayer(y, x);

        //if(victory == 0)    
        //    victory = board.moveEnemys('E', 1, 1);

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
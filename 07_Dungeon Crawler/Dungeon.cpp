#include <iostream>
#include <vector>
#include <string>
#include "Dungeon.hpp"
#include "generic.hpp"

using std::cout; using std::endl;
using std::vector; using std::string;
using std::cerr;

typedef vector<string>::size_type size;

//future corrections:
//    insert a size check routine on initBoard. ???
//    insert a input check on movePlayer.
//    test try and catch keywords use on later development steps
//      Add a namecheck try and throw algorithm on initEnemy
//    transform the entire program into a full OOP thing... maybe??

void Dungeon::initBoard (const int x, const int y, const int traps){
    size rowCnt = x, colCnt = y;
    vector<char> xAxis;
    for (size j = 0; j != colCnt; ++j){
        xAxis.push_back('.');
    }

    for (size i = 0; i != rowCnt; ++i){
        coords.push_back(xAxis);
    }
    player.name = 'P';
    entitys.push_back(player);
    coords[1][1] = player.name;
    coords[rowCnt - 1][colCnt - 1] = 'X';

    //initializes traps (fixed entitys)
    initEnemys(traps, 'T');
}

void Dungeon::initEnemys(const int amountOfEnemys, const char name){
    for (int i = 0; i < amountOfEnemys; i++){
        Entity enemy;
        enemy.name = name;
        randomPositioning(enemy);
        entitys.push_back(enemy);
    }
}

void Dungeon::randomPositioning(Entity& entity){
    bool positioned = false;
    while (!positioned){
        size row = 0,
            col = randomNumber (0, (coords.size())*(coords[0].size()));

        while (col > coords[0].size()){
            col -= coords[0].size();
            row++;
        }
        
        if (coords[row][col] == '.'){
            coords[row][col] = entity.name;
            entity.yAxis = row;
            entity.xAxis = col;
            positioned = true;
        }
    }
}

void Dungeon::print () {
    size rowCnt = coords.size(), colCnt = coords[0].size(),
        border = (coords[0].size() - 1);
    cout << endl;
    for (size i = 0; i != rowCnt; ++i){
        for (size j = 0; j != colCnt; ++j){
            cout << coords[i][j];
            if (j == border){
                cout << "\n";
            } else {
                cout << " ";
            }
        }
    }
    cout << "\n" << endl;
}

int Dungeon::moveEnemys (const char id){
    for (int i = 0; i < entitys.size(); i++){
        Entity temp = entitys[i];

        coords[temp.yAxis][temp.xAxis] = '.';
        if (temp.name == id){

            bool moved = false;
            int overload = 0;
            while (!moved){
                int row = 0, col = 0, direction = randomNumber(0, 4);
                if (overload == 100){
                    direction = 4;
                }
                
                switch (direction){
                    case 0:
                        row = -1;
                        col = 0;
                    break;
                    case 1:
                        row = 0;
                        col = -1;
                    break;
                    case 2:
                        row = 1;
                        col = 0;
                    break;
                    case 3:
                        row = 0;
                        col = 1;
                    break;
                    case 4:
                        row = 0;
                        col = 0;
                }

                Entity temp2 = temp;
                moveLimitCheck
                    (temp2.yAxis + row, temp2.xAxis + col, temp2);
                
                switch (coords[temp2.yAxis][temp2.xAxis]){
                    case '.':
                        entitys[i] = temp2;
                        moved = true;
                    break;
                    case 'P':
                        return -1;
                    break;
                    default:
                        overload++;                    
                }
            }
        }

        coords[entitys[i].yAxis][entitys[i].xAxis] = entitys[i].name;
    }
    return 0;
}

int Dungeon::movePlayer(const int rowDir, const int colDir){
    int yPos = player.yAxis + rowDir;
    int xPos = player.xAxis + colDir;
    coords[player.yAxis][player.xAxis] = '.';

    moveLimitCheck(yPos, xPos, player);

    entitys[0] = player;
    switch (coords[player.yAxis][player.xAxis]){
        case '.':
            coords[player.yAxis][player.xAxis] = player.name;
            return 0;
        break;
        case 'X':
            return 1;
        break;
        default:
            return -1;
        break;
    }
}

void Dungeon::moveLimitCheck(const int& yNewPos,const int& xNewPos, Entity& toMove){    
    if (!(yNewPos < 0 || yNewPos >= coords.size())){
        toMove.yAxis = yNewPos;
    }
    if (!(xNewPos < 0 || xNewPos >= coords[0].size())) {
        toMove.xAxis = xNewPos;
    }
}

#include <string>
#include <iostream>
#include <sstream>
#include "Tic_Tac_Toe.hpp"

using std::string; using std::cout;
using std::stringstream;
using std::endl;

void initializer (TTT& gData){
    int slotCnt = 1;
    constexpr size_t rowCnt = 3, colCnt = 3;
    for (size_t i = 0; i != rowCnt; ++i){
        for (size_t j = 0; j != colCnt; ++j){
            stringstream ss;
            ss << slotCnt;
            string temp;
            ss >> temp;
            gData.slots[i][j] = " " + temp;
            ++slotCnt;
        }
    }
}

void printBoard (const TTT& gData){
    constexpr size_t rowCnt = 3, colCnt = 3, border = 2;
    cout << endl;
    for (size_t i = 0; i != rowCnt; ++i){
        for (size_t j = 0; j != colCnt; ++j){
            cout << gData.slots[i][j];
            //if not on the horizontal border
            if (j != border){
                cout << gData.board[0];
            }
        }
        //if not on the vertical border
        if (i != border){
            cout << gData.board[1];
        }
    }
    cout << "\n" << endl;
}

bool boardUpdate (TTT& toUpdate,const int& slot, const bool& turn){
    string player, content;
    size_t rowCnt = 0, colCnt = slot;
    bool update = false;

    player = turn? " X": " O";
    colCnt -= 1;
    while (colCnt > 2){
        colCnt -= 3;
        ++rowCnt;
    }
    
    content = toUpdate.slots[rowCnt][colCnt];
    update = (content != " X" || content != " O")? true: false;
    if (update){
        toUpdate.slots[rowCnt][colCnt] = player;
    }
    return update;
}

bool drawCheck (const TTT& toCheck){
    string X = " X", O = " O";
    size_t totalX = 0, totalO = 0, rowCnt = 3, colCnt = 3;

    for (size_t i = 0; i != rowCnt; ++i){
        for (size_t j = 0; j != colCnt; ++j){
            if (toCheck.slots[i][j] == X){
                ++totalX;
            }
            else if (toCheck.slots[i][j] == O){
                ++totalO;
            }
        }
    }

    bool draw = false;
    if (totalX + totalO == rowCnt * colCnt){
        draw = true;
    }
    return draw;
}

string winnerCheck (const TTT& toCheck){
    constexpr size_t rowCnt = 3, colCnt = 3;
    bool gEnd = false, pairCheck = true;
    int matchCnt = 0;
    string winner, content, sample;

    //horizontal and vertical pair check
    for (int i = 0; i < 2 && !gEnd; ++i){
        for (size_t i = 0; !gEnd && i != rowCnt; ++i){
            content = pairCheck? toCheck.slots[i][0]:toCheck.slots[0][i];
            sample = content;
            matchCnt = 0;

            for (size_t j = 0; j != colCnt; ++j){
                content = pairCheck? toCheck.slots[i][j]:
                    toCheck.slots[j][i];
                if (content == sample){
                    ++matchCnt;
                }
                if (matchCnt == rowCnt){
                    gEnd = true;
                }
            }
        }
        pairCheck = !pairCheck;
    }

    //left and right diagonal check respectively
    for (int i = 0; i < 2 && !gEnd; ++i){
        content = pairCheck? toCheck.slots[0][0]:
            toCheck.slots[0][colCnt - 1];
        sample = content;
        matchCnt = 0;

        if (pairCheck){
            for (size_t i = 0; i != rowCnt; ++i){
                content = toCheck.slots[i][i];
                if (content == sample){
                    ++matchCnt;
                }
            }
        } else {
            for (size_t i = 0, j = colCnt; i != rowCnt; ++i){
                --j;
                content = toCheck.slots[i][j];
                if (content == sample){
                    ++matchCnt;
                }
            }
        }

        if (matchCnt == rowCnt){
            gEnd = true;
        }
        pairCheck = !pairCheck;
    }

    if (!gEnd){
        if (drawCheck(toCheck)){
            sample = " Draw";
            gEnd = true;
        } else {
            sample = "";
        }
    }
    return sample;
}

void gameReset (TTT& toReset){
    cout << "The game will be reset: " << endl;
    initializer(toReset);
    printBoard(toReset);
}
#ifndef GUARD_TIC_TAC_TOE
#define GUARD_TIC_TAC_TOE

#include <string>

struct TTT {
    std::string slots[3][3];
    std::string board[2] = {" |","\n---+---+---\n"};
};

void initializer (TTT&);
void printBoard (const TTT&);
bool boardUpdate (TTT&,const int&, const bool&);
bool drawCheck (const TTT&);
//returns draw, the winner or "" if there is none yet.
std::string winnerCheck (const TTT&);
void gameReset (TTT&);

#endif
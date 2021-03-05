#ifndef GUARD_DUNGEON
#define GUARD_DUNGEON

#include <string>
#include <vector>

#include "Entity.hpp"

class Dungeon {
public:
    Dungeon()
        { initBoard(); }
    Dungeon(const int totalRows, const int totalCols, const int totalTraps)
        { initBoard(totalRows, totalCols, totalTraps); }
    
    //add try catch block inside the function to garantee a minimum number of rows and columns
    void initBoard(const int x = 10, const int y = 10, const int traps = 10);
    void initEnemys(const int, const char);
    void print();

    int moveEnemys(const char);
    int movePlayer(const int,const int);

    Entity getPlayer() { return player; }

private:
    void randomPositioning(Entity&);
    void moveLimitCheck(const int&, const int&, Entity&);

    std::vector<std::vector<char>> coords;
    std::vector<Entity> entitys;
    Entity player;
};

#endif
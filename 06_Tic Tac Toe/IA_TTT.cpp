#include <chrono>
#include <random>
#include "Tic_Tac_Toe.hpp"
#include "IA_TTT.hpp"

void IA_turn (TTT& board, const bool& player){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    std::uniform_int_distribution<int> distribution(1,9);

    //it repeats while as long as a valid number is not chosen
    while (!boardUpdate(board, distribution(generator), player));
}
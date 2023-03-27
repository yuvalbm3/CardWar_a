#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "game.hpp"
#include "player.hpp"

using ariel::Game;
using ariel::Player;

Game::Game(Player p1, Player p2):
 _p1(p1), _p2(p2)
{
    std::cout << "1";
}

string Game::printLastTurn(){
    return "printLastTurn";
}

void Game::playTurn(){
    std::cout << "playTurn";
}

void Game::playAll(){
    std::cout << "playAll";
}

void Game::printWiner(){
    std::cout << "printWiner";
}

void Game::printLog(){
    std::cout << "printLog";
}

void Game::printStats(){
    std::cout << "printStats";
}






























// typedef struct game
// {
//     Player _p1;
//     Player _p2;

// }Game;

// class game{
// private:
//     Player _p1;
//     Player _p2;
// public:
    // game(Player p1, Player p2){
    //     _p1 = p1;
    //     _p2 = p2;
    // };
    // string printLastTurn();
    // void playTurn();
    // void playAll();
    // void printWiner();
    // void printLog();
    // void printStats();
//};
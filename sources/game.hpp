#ifndef GAME_HPP
#define GAME_HPP
#include "player.hpp"

namespace ariel{
    class Game{
    public:
        Player _p1;
        Player _p2;
        Game();
        Game(Player, Player);
        std::string printLastTurn();
        void playTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();

    private:
        std::string _name;
    };
}
#endif
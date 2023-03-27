#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "card.hpp"
#include <string>

namespace ariel{

    class Player{
    public:
        Player(std::string);
        Player();
        std::string getName();   //return the player name
        int stacksize();
        int cardesTaken();
        void setName(std::string);

    private:
        std::string _name;
    };

}

#endif
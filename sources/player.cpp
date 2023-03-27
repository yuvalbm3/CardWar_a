#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;

#include "card.hpp"
#include "player.hpp"

using ariel::Card;
using ariel::Player;


std::string _name;
Player::Player(string nam){
    _name = nam;
}

Player::Player(){
    _name = "name";
}

std::string Player::getName(){
    return _name;
}

void Player::setName(std::string name){
    _name = name;
}

int Player::stacksize(){
    return 1;
}
int Player::cardesTaken(){
    return 1;
}

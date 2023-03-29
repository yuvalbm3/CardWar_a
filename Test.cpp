//I've used chatGPT to convert output print onto string in line 68

#include <iostream>
#include <stdexcept>
#include <sstream>
#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include <string>
using namespace std;
using namespace ariel;


TEST_CASE("Play the game") {
//initial the game
    Player p1("Kobi");
    Player p2("Bobi");
    Game game(p1,p2);
//Game start
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK_EQ(p1.stacksize(), p2.stacksize());
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken()==0);
    CHECK_EQ(p1.cardesTaken(), p2.cardesTaken());
//Game is running
//play 5 turns
    for(int i=0 ; i<5 ; i++){
        CHECK_NOTHROW(game.playTurn());
    }
//Initial boolean variables
    bool stackTest = false;
    bool cardsTakenTest = false;
//at least one of the player going to lose cards.
    CHECK(p1.stacksize() <= 26);
    CHECK(p2.stacksize() <= 26);
    if(p1.stacksize() < 26 || p2.stacksize() < 26){
        stackTest = true;
    }
    CHECK(stackTest);
//at least one of the player going to win cards.
    CHECK(p1.cardesTaken() >= 0);
    CHECK(p2.cardesTaken() >= 0);
    if(p1.cardesTaken() > 0 || p2.cardesTaken() > 0){
        cardsTakenTest = true;
    }
    CHECK(cardsTakenTest);
    CHECK_EQ(stackTest, cardsTakenTest);
//continue play
    game.playAll();
//At the end of the game the sum of all cards taken must be 26
    CHECK(p1.cardesTaken() + p2.cardesTaken() == 52);
//At the end of the game, both player have 0 cards in their stacks
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    CHECK_EQ(p1.stacksize(), p2.stacksize());
}

TEST_CASE("Check the winner"){
    Player p1("Kobi");
    Player p2("Bobi");
    Game game(p1,p2);
    game.playAll();
//convert print to string
    std::ostringstream oss;
    game.printWiner();
    std::string output = oss.str();
//check who won
    if (p1.getName() == output){
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    CHECK_EQ(p1.stacksize(), p2.stacksize());
    CHECK(p1.cardesTaken() > p2.cardesTaken());
    CHECK_EQ(p1.cardesTaken() + p2.cardesTaken(), 52);
    }
    else if (p2.getName() == output){
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    CHECK_EQ(p1.stacksize(), p2.stacksize());
    CHECK(p1.cardesTaken() < p2.cardesTaken());
    CHECK_EQ(p1.cardesTaken() + p2.cardesTaken(), 52);
    }
};

TEST_CASE("THROWS exceptions"){
//Initial game with only one player
    Player p1("Kobi");
    Player p2("Bobi");
    CHECK_THROWS(Game(p1,p1));
    
    Game game(p1,p2);
    game.playAll();
//Can't play another turn cause all turn were played already
    CHECK_THROWS(game.playTurn());
    CHECK_THROWS(game.playAll());
};


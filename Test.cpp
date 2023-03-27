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


TEST_CASE("Setup the game") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken()==0);
}

TEST_CASE("Check the winner"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playAll();
    //convert print to string
    std::ostringstream oss;
    game.printWiner();
    std::string output = oss.str();
    if (p1.getName() == output){
        CHECK(p1.stacksize() == 52);
        CHECK(p2.stacksize() == 0);
        CHECK(p1.cardesTaken() == 26);
        CHECK(p2.cardesTaken()==0);
    }
    else if (p2.getName() == output){
        CHECK(p2.stacksize() == 52);
        CHECK(p1.stacksize() == 0);
        CHECK(p2.cardesTaken() == 26);
        CHECK(p1.cardesTaken()==0);
    }
};

TEST_CASE("Test 3 - different players"){
    string ali = "Alice";
    Player p1(ali);
    Player p2(ali);
    CHECK(p1.getName() != p2.getName());
};
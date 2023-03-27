#ifndef CARD_HPP
#define CARD_HPP

namespace ariel{
    class Card{
    private:
        struct cardData {
            enum Rank { A, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, HIGTH, NINE, TEN, J, Q, K };
            enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };
            Rank rank;
            Suit suit;
        };
    public:
        int stacksize();
        int cardesTaken();
    };
}
#endif
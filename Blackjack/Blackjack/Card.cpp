#include"Card.h"

using namespace std;


Card::Card(Suit suit, Rank rank) {
    this->suit = suit;
    this->rank = rank;
}

Card::Suit Card::get_suit() const {
    return suit;
}

Card::Rank Card::get_rank() const {
    return rank;
}

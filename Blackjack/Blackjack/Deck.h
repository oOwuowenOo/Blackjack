#pragma once
#include"Card.h"

class Deck {
public:
    Deck();
    void shuffle();
    Card draw_card();

private:
    Card cards[52];
    int num_drawn;
};

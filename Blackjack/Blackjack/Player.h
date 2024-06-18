#pragma once
#include<string>
#include"Card.h"

class Player {
public:
    Player();
    Player(string name);
    void draw_card(Card card);
    int get_score();
    void print_cards();

private:
    string name;
    Card cards[10];
    int num_cards;
};

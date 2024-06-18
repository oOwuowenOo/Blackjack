#pragma once
#include"Player.h"
#include"Deck.h"
#include"Card.h"
using namespace std;

class Game {
public:
    Game(string player_name);
    void play();

private:
    Deck deck;
    Player player;
    Player dealer;
};
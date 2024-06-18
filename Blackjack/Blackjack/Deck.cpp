#include <iostream>
#include <cstdlib>
#include <ctime>
#include"Deck.h"

using namespace std;

Deck::Deck() {
    num_drawn = 0;
    int i = 0;
    for (int s = 0; s < 4; s++) {
        for (int r = 1; r <= 13; r++) {
            cards[i] = Card(static_cast<Card::Suit>(s), static_cast<Card::Rank>(r));       //用static_cast把s,r轉換成Suit和Rank，並以此建構出一副撲克牌
            i++;
        }
    }
}

void Deck::shuffle() {
    srand(time(0));
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;
        Card temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

Card Deck::draw_card() {
    Card card = cards[num_drawn];
    num_drawn++;
    return card;
}

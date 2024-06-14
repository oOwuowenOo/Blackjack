#include <iostream>
#include"Player.h"

using namespace std;

Player::Player() {
    name = "";
    num_cards = 0;
}
Player::Player(string name) {
    this->name = name;
    num_cards = 0;
}

void Player::draw_card(Card card) {
    cards[num_cards] = card;
    num_cards++;
}

int Player::get_score() {
    int score = 0;
    int num_aces = 0;
    for (int i = 0; i < num_cards; i++) {
        int rank = cards[i].get_rank();
        if (rank >= 10) {
            score += 10;
        }
        else if (rank == Card::ACE) {
            num_aces++;
            score += 11;
        }
        else {
            score += rank;
        }
    }
    while (score > 21 && num_aces > 0) {
        score -= 10;
        num_aces--;
    }
    return score;
}

void Player::print_cards() {
    cout << name << " 有 ";
    for (int i = 0; i < num_cards; i++) {
        int rank = cards[i].get_rank();
        switch (cards[i].get_suit()) {
        case Card::Suit::CLUB:
            cout << "梅花";
            break;
        case Card::Suit::DIAMOND:
            cout << "方塊";
            break;
        case Card::Suit::HEART:
            cout << "紅心";
            break;
        case Card::Suit::SPADE:
            cout << "黑桃";
            break;
        }
        switch (rank) {
        case Card::ACE:
            cout << "A ";
            break;
        case Card::JACK:
            cout << "J ";
            break;
        case Card::QUEEN:
            cout << "Q ";
            break;
        case Card::KING:
            cout << "K ";
            break;
        default:
            cout << rank << " ";
            break;
        }

    }
    cout << endl;
}

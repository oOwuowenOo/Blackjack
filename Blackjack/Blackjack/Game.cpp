#include <iostream>
#include <cstdlib>
#include <ctime>
#include"Game.h"

using namespace std;

Game::Game(string player_name) : player(player_name) {}

void Game::play() {
    deck.shuffle();
    player.draw_card(deck.draw_card());
    dealer.draw_card(deck.draw_card());
    player.draw_card(deck.draw_card());
    dealer.draw_card(deck.draw_card());
    player.print_cards();

    while (player.get_score() < 21) {
        char input;
        cout << "�A�n���? (y/n) ";
        cin >> input;
        cout << endl<<"=====================================" << endl;
        if (input == 'y') {
            player.draw_card(deck.draw_card());
            player.print_cards();
        }
        else {
            break;
        }
    }

    int dealer_score = dealer.get_score();
    while (dealer_score < 17) {
        dealer.draw_card(deck.draw_card());
        dealer_score = dealer.get_score();
    }

    player.print_cards();
    cout << "���a ";
    dealer.print_cards();

    int player_score = player.get_score();
    if (player_score > 21) {
        cout << "�A�z�P! ���aĹ!" << endl;
    }
    else if (dealer_score > 21) {
        cout << "���a�z�P! �AĹ!" << endl;
    }
    else if (player_score > dealer_score) {
        cout << "�AĹ !" << endl;
    }
    else if (dealer_score > player_score) {
        cout << "���aĹ !" << endl;
    }
    else {
        cout << "���� !" << endl;
    }
}

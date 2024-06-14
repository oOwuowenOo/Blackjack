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
        cout << "你要跟嗎? (y/n) ";
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
    cout << "莊家 ";
    dealer.print_cards();

    int player_score = player.get_score();
    if (player_score > 21) {
        cout << "你爆牌! 莊家贏!" << endl;
    }
    else if (dealer_score > 21) {
        cout << "莊家爆牌! 你贏!" << endl;
    }
    else if (player_score > dealer_score) {
        cout << "你贏 !" << endl;
    }
    else if (dealer_score > player_score) {
        cout << "莊家贏 !" << endl;
    }
    else {
        cout << "平手 !" << endl;
    }
}

#include <iostream>
#include <cstdlib>
#include <ctime>
#include"Game.h"
using namespace std;

int main() {
    string player_name;
    cout << "輸入名字: ";
    cin >> player_name;

    int n = 1;
    while(n != -1)
    {
        Game game(player_name);
        game.play();
        cout << "輸入-1結束遊戲，輸入-1以外的【數字】繼續: ";
        cin >> n;
        cout << "\n\n\n<<===================新的一局===================>>\n";
    }

    return 0;
}
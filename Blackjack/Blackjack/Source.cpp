#include <iostream>
#include <cstdlib>
#include <ctime>
#include"Game.h"
using namespace std;

int main() {
    string player_name;
    cout << "��J�W�r: ";
    cin >> player_name;

    int n = 1;
    while(n != -1)
    {
        Game game(player_name);
        game.play();
        cout << "��J-1�����C���A��J-1�H�~���i�Ʀr�j�~��: ";
        cin >> n;
        cout << "\n\n\n<<===================�s���@��===================>>\n";
    }

    return 0;
}
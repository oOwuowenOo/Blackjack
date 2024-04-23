#include "blackjack.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    using namespace std;

    cout << "歡迎來到21點遊戲！" << endl;

    char playAgain;
    do {
        BlackjackGame game;//建立遊戲
        game.play();//遊玩

        cout << "是否要再玩一次？(y/n): ";
        cin >> playAgain;
        cout << endl;
    } while (playAgain == 'y');

    cout << "謝謝您的遊玩！" << endl;

    return 0;
}

#include "blackjack.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    using namespace std;

    cout << "�w��Ө�21�I�C���I" << endl;

    char playAgain;
    do {
        BlackjackGame game;//�إ߹C��
        game.play();//�C��

        cout << "�O�_�n�A���@���H(y/n): ";
        cin >> playAgain;
        cout << endl;
    } while (playAgain == 'y');

    cout << "���±z���C���I" << endl;

    return 0;
}

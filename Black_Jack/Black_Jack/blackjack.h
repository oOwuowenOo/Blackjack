#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <iostream>
#include <string>

using namespace std;

class BlackjackGame {
private:
    int playerScore;//���a�I��
    int dealerScore;//���a�I��
    bool playerBusted;//���a�O�_�z��
    bool dealerBusted;//���a�O�_�z��

    int generateCardValue();//���
    void showInitialHands();//�i�ܤ��
    void playerTurn();//���a�^�X
    void dealerTurn();//���a�^�X
    void showResult();//��ܵ��G

public:
    BlackjackGame();//�غc�l
    void play();//�C���}�l
};

#endif

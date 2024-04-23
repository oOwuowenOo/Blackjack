#include "blackjack.h"

#include <iostream>
#include <string>

using namespace std;

BlackjackGame::BlackjackGame() {//�غc�l
    playerScore = 0;
    dealerScore = 0;
    playerBusted = false;
    dealerBusted = false;
}

int BlackjackGame::generateCardValue() {//���1~11�I
    return rand() % 10 + 1;
}

void BlackjackGame::showInitialHands() {//�i�̶ܳ}�l���
    cout << "�A���P�O�G" << endl;
    playerScore = generateCardValue() + generateCardValue();//���a��2�i��P
    cout << "�`�I�ơG" << playerScore << endl;
    cout<< "===========================" << endl;
    cout << "���a���P�O�G" << endl;
    dealerScore = generateCardValue() + generateCardValue();//���a��2�i��P
    cout << "�`�I�ơG" << dealerScore << endl;
}

void BlackjackGame::playerTurn() {//���a�^�X
    char choice;
    while (playerScore < 21) {//�u�n�S�W�L21���i�H�M�w�n���n�~���P
        cout << "�O�_�n�s�P�H(y/n): ";
        cin >> choice;
        if (choice == 'y') {//��Jy�ө�
            int cardValue = generateCardValue();
            cout << "�A���F�@�i�P�A�I�ơG" << cardValue << endl;
            playerScore += cardValue;
            cout << "�`�I�ơG" << playerScore << endl;
        }
        else {//��Jn����
            break;
        }
    }
    if (playerScore > 21) {//�P�_�O�_�z�P
        cout << "�A�z�P�F�I" << endl;
        playerBusted = true;
    }
}

void BlackjackGame::dealerTurn() {//���a�^�X
    while (dealerScore < 17) {//�p�G�I�Ƥ���17�N�~���P
        int cardValue = generateCardValue();
        cout << "���a���F�@�i�P�A�I�ơG" << cardValue << endl;
        dealerScore += cardValue;
        cout << "�`�I�ơG" << dealerScore << endl;
    }
    if (dealerScore > 21) {//�P�_�O�_�z�P
        cout << "���a�z�P�F�I" << endl;
        dealerBusted = true;
    }
}

void BlackjackGame::showResult() {//��ܵ��G
    if (playerBusted) {//�p�G���a�z�P �N��������
        cout << "�A�z�P�F�A�鱼�F�o���C���C" << endl;
    }
    else if (dealerBusted || playerScore > dealerScore) {//���a�z�P�Ϊ��a����j ���aĹ
        cout << "���ߡA�AĹ�o�F�o���C���I" << endl;
    }
    else if (playerScore == dealerScore) {//�I�Ƥ@�˥���
        cout << "�����I" << endl;
    }
    else {//��F
        cout << "�A�鱼�F�o���C���C" << endl;
    }
}

void BlackjackGame::play() {//�C���}�l
    srand(time(NULL));//��l�ƶü�
    showInitialHands();//�i�ܤ��
    playerTurn();//���a�^�X
    if (!playerBusted) {//�p�G���a�S�z�ơA���ˮa��
        dealerTurn();
    }
    showResult();//�i�̲ܳ׵��G
}

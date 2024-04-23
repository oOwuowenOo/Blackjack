#include "blackjack.h"

#include <iostream>
#include <string>

using namespace std;

BlackjackGame::BlackjackGame() {//建構子
    playerScore = 0;
    dealerScore = 0;
    playerBusted = false;
    dealerBusted = false;
}

int BlackjackGame::generateCardValue() {//抽排1~11點
    return rand() % 10 + 1;
}

void BlackjackGame::showInitialHands() {//展示最開始手排
    cout << "你的牌是：" << endl;
    playerScore = generateCardValue() + generateCardValue();//玩家先2張抽牌
    cout << "總點數：" << playerScore << endl;
    cout<< "===========================" << endl;
    cout << "莊家的牌是：" << endl;
    dealerScore = generateCardValue() + generateCardValue();//莊家先2張抽牌
    cout << "總點數：" << dealerScore << endl;
}

void BlackjackGame::playerTurn() {//玩家回合
    char choice;
    while (playerScore < 21) {//只要沒超過21都可以決定要不要繼續抽牌
        cout << "是否要叫牌？(y/n): ";
        cin >> choice;
        if (choice == 'y') {//輸入y來抽
            int cardValue = generateCardValue();
            cout << "你抽到了一張牌，點數：" << cardValue << endl;
            playerScore += cardValue;
            cout << "總點數：" << playerScore << endl;
        }
        else {//輸入n不抽
            break;
        }
    }
    if (playerScore > 21) {//判斷是否爆牌
        cout << "你爆牌了！" << endl;
        playerBusted = true;
    }
}

void BlackjackGame::dealerTurn() {//莊家回合
    while (dealerScore < 17) {//如果點數不到17就繼續抽牌
        int cardValue = generateCardValue();
        cout << "莊家抽到了一張牌，點數：" << cardValue << endl;
        dealerScore += cardValue;
        cout << "總點數：" << dealerScore << endl;
    }
    if (dealerScore > 21) {//判斷是否爆牌
        cout << "莊家爆牌了！" << endl;
        dealerBusted = true;
    }
}

void BlackjackGame::showResult() {//顯示結果
    if (playerBusted) {//如果玩家爆牌 就直接結束
        cout << "你爆牌了，輸掉了這輪遊戲。" << endl;
    }
    else if (dealerBusted || playerScore > dealerScore) {//莊家爆牌或玩家比較大 玩家贏
        cout << "恭喜，你贏得了這輪遊戲！" << endl;
    }
    else if (playerScore == dealerScore) {//點數一樣平局
        cout << "平局！" << endl;
    }
    else {//輸了
        cout << "你輸掉了這輪遊戲。" << endl;
    }
}

void BlackjackGame::play() {//遊戲開始
    srand(time(NULL));//初始化亂數
    showInitialHands();//展示手排
    playerTurn();//玩家回合
    if (!playerBusted) {//如果玩家沒爆排，換裝家抽
        dealerTurn();
    }
    showResult();//展示最終結果
}

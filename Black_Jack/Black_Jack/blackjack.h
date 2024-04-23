#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <iostream>
#include <string>

using namespace std;

class BlackjackGame {
private:
    int playerScore;//玩家點數
    int dealerScore;//莊家點數
    bool playerBusted;//玩家是否爆排
    bool dealerBusted;//莊家是否爆排

    int generateCardValue();//抽排
    void showInitialHands();//展示手排
    void playerTurn();//玩家回合
    void dealerTurn();//莊家回合
    void showResult();//顯示結果

public:
    BlackjackGame();//建構子
    void play();//遊戲開始
};

#endif

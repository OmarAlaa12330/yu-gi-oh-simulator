#pragma once

#include "Player.hpp"

class Game {
public:
    Player* player;
    Player* opponent;
    Player* currentPlayer;

    Game(Player* p1, Player* p2): player(p1), opponent(p2), currentPlayer(p1) {}

    void drawPhase(){
        std::cout << currentPlayer->name << " is drawing a card...\n";
        currentPlayer->drawCard();
    }

    void mainPhase1(){}

    void standPhase(){}

    void battlePhase(){}

    void mainPhase2() {}

    void endPhase() {
        std::cout << currentPlayer->name << " is ending their turn...\n";
        switchTurn();
    }

    void switchTurn() {
        currentPlayer = (currentPlayer == player) ? opponent : player;
    }
};
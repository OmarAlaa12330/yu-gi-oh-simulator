#pragma once

#include <string>
#include <iostream>
#include "Card.hpp"
#include "Deck.hpp"

class Player{
public:
    std::string name;
    Deck deck;
    std::vector<Card*> hand;
    MonsterCard* monstersField[5]= {0};
    Card* spellsField[5] = {0};
    int lifePoints;

    Player(Deck d): deck(d) {
        lifePoints = 8000;

    }


    void takeDamage(int dmg) {
        lifePoints-=dmg;
        std::cout << name << " takes " << dmg << "damage!\n";
    }

    void drawCard() {
        if (!deck.isEmpty()) {
            hand.push_back(deck.drawCard());
        } else {
            std::cout << "Deck is empty you flippin' donut!\n";
        }
    }

    void drawCards(int num) {
        for (int i = 0; i <= num; i++)
            drawCard();
    }


    void normalSummon(Card* monster) {}





};
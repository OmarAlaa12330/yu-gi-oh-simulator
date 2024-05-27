#pragma once

#include "Player.hpp"

class Effect {
public:
    virtual void activate(Player* player1, Player* opponent) = 0;
};

class DamageEffect: public Effect {
private:
    int damage;
public:
    DamageEffect(int dmg) : damage(dmg){}
    void activate(Player* player1, Player* opponent) override {
        opponent -> takeDamage(damage);
    }
};

class DrawCardEffect: public Effect {
private:
    int numCards;
public:
    DrawCardEffect(int num_cards) : numCards(num_cards) {}
    void activate(Player* player, Player* opponent) override {
        player->drawCards(numCards);
    }
};

class HealEffect: public Effect {
private:
    int amount;
public:
    HealEffect(int amt) : amount(amt) {}
    void activate(Player* player, Player* opponent) override {
        player->lifePoints += amount;
        std::cout << player->name << " heals " << amount << " life points!\n";
    }
};



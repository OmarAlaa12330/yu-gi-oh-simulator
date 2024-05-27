#pragma once

#include <string>
#include <vector>

#include "Effect.hpp"
#include "Player.hpp"


class Card {
public:
    std::string name;
    std::string cardType;
    std::string description;
    std::vector<Effect*> effects{};
    bool flipped = false;

    Card(std::string n, std::string ct, std::string d) : name(n), cardType(ct), description(d) {}

    virtual void activate(Player* player, Player* opponent) = 0; // Pure virtual method

    virtual void activateEffects(Player* player, Player* opponent) {
        for (Effect* effect : effects){
            effect->activate(player, opponent);
        }
    }

};

class MonsterCard: public Card {
public:
    int attack;
    int defense;
    int level;

    MonsterCard(std::string n, std::string d, int atk, int def, int lvl)
        : Card(n, "Monster", d), attack(atk), defense(def), level(lvl){}

    bool isDestroyedByBattle(int atk_points) const {
        return atk_points >=defense;
    }



};

class SpellCard: public Card {
public:
    SpellCard(std::string n, std::string  d) : Card(n, "Spell", d){}

    void activate(Player* player, Player* opponent) override {
        std::cout << "Activating spell: " << name << std::endl;
        activateEffects(player, opponent);
    }
};

class TrapCard : public Card {
public:
    TrapCard(std::string n, std::string d) : Card(n, "Trap", d) {}

    void activate(Player* player, Player* opponent) override {
        std::cout << "Activating trap: " << name << "!\n";
        activateEffects(player, opponent);
    }
};




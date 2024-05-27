#include "Card.hpp"

class Fireball: public SpellCard {
public:
    Fireball(): SpellCard("Fireball", "Deal 1000 damage to your opponent.") {
        effects.push_back(new DamageEffect(1000));
    }
};

class HealingPotion : public SpellCard {
public:
    HealingPotion() : SpellCard("Healing Potion", "Heal 500 life points") {
        effects.push_back(new HealEffect(500));
    }
};

class PotOfGreed : public SpellCard {
public:
    PotOfGreed() : SpellCard("Pot of greed", "Draw 2 cards") {
        effects.push_back(new DrawCardEffect(2));
    }
};

class MirrorForce: public TrapCard {
public:
    MirrorForce() : TrapCard("Mirror Force", "Destroy all attack position monsters your opponent controls"){}

    void activate(Player* player, Player* opponent) override {
        std::cout << "Activate trap: " << name << std::endl;
        for (int i = 0; i <= 5; i++) {
            MonsterCard* monster = opponent->monstersField[i];
            if (monster) {
                opponent->monstersField[i] = nullptr;
                std::cout << opponent->name << "'s" << monster->name << " is destroyed!\n";
                // delete monster;
            }
        }
    }
};

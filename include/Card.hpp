#pragma once

#include <string>
#include <vector>

#include "Effect.hpp"
#include "Player.hpp"


class Card {
public:
    Card(std::string n, std::string ct, std::string d);
    ~Card();

    virtual void activate(Player* player, Player* opponent) = 0; // Pure virtual method
    virtual void activateEffects(Player* player, Player* opponent);

public:
    const std::string name;
    const std::string cardType;
    const std::string description;
    const std::vector<Effect*> effects{};
    bool flipped = false;
};

class MonsterCard: public Card {
public:
    MonsterCard(std::string n, std::string d, int atk, int def, int lvl);

    bool isDestroyedByBattle(int atk_points) const;

public:
    int attack;
    int defense;
    int level;
};

class SpellCard: public Card {
public:
    SpellCard(std::string n, std::string d);

    void activate(Player* player, Player* opponent) override;
};

class TrapCard : public Card {
public:
    TrapCard(std::string n, std::string d);

    void activate(Player* player, Player* opponent) override;
};




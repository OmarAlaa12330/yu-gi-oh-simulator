#include "../include/Card.hpp"

Card::Card(std::string n, std::string ct, std::string d)
    : name(n), cardType(ct), description(d) {}

Card::~Card() {
    for (Effect* effect: effects) {
        effect = nullptr;
    }
}

void Card::activateEffects(Player* player, Player* opponent) {
    for (Effect* effect: effects){
        effect->activate(player, opponent);
    }
}


MonsterCard::MonsterCard(std::string n, std::string d, int atk, int def, int lvl)
        : Card(n, "Monster", d), attack(atk), defense(def), level(lvl){}

bool MonsterCard::isDestroyedByBattle(int atk_points) const {
    return atk_points >=defense;
}

SpellCard::SpellCard(std::string n, std::string d) : Card(n, "Spell", d){}

void SpellCard::activate(Player *player, Player *opponent) {
    std::cout << "Activating spell: " << name << std::endl;
    activateEffects(player, opponent);
}

TrapCard::TrapCard(std::string n, std::string d)
    : Card(n, "Trap", d) {}

void TrapCard::activate(Player *player, Player *opponent) {
    std::cout << "Activating trap: " << name << "!\n";
    activateEffects(player, opponent);
}

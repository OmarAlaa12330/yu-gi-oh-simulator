#pragma once

#include "Card.hpp"


class PlayerField {
public:
    PlayerField();
    ~PlayerField();

    void placeMonsterCard(Card* card);
    void placeSpellTrapCard(Card* card);
    void removeMonsterCard(int pos);
    void removeSpellTrapCard(int pos);

    bool isFullMonsters();
    bool isFullSpellTraps();


private:
    Card* m_monsterZone[5];
    Card* m_spellTrapZone[5];
    char m_numMonsters;
    char m_numSpellTraps;
};

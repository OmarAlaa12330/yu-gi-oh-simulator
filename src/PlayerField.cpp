#include "../include/PlayerField.hpp"

PlayerField::PlayerField() {
    Card* m_monsterZone[5]= {nullptr};
    Card* m_spellTrapZone[5]= {nullptr};
    m_numMonsters = 0;
    m_numSpellTraps = 0;
}

PlayerField::~PlayerField() {
    for (int i = 0; i < 5; i++) {
        m_monsterZone[i] = nullptr;
        m_spellTrapZone[i] = nullptr;
    }
}

void PlayerField::placeMonsterCard(Card* card){
    for (int i = 0; i<5; i++){
        if (m_monsterZone[i] == nullptr) {
            m_monsterZone[i] = card;
            m_numMonsters++;
            break;
        }
    }
}

void PlayerField::placeSpellTrapCard(Card* card) {
    for (int i = 0; i<5; i++){
        if (m_spellTrapZone[i] == nullptr) {
            m_spellTrapZone[i] = card;
            m_numSpellTraps++;
            break;
        }
    }
}

void PlayerField::removeMonsterCard(int pos) {
    if (pos >= 0 && pos < 5) {
        m_monsterZone[pos] = nullptr;
        m_numMonsters--;
    }
}

void PlayerField::removeSpellTrapCard(int pos) {
    if (pos >= 0 && pos < 5) {
        m_spellTrapZone[pos] = nullptr;
        m_numSpellTraps--;
    }
}

bool PlayerField::isFullMonsters() {
    return m_numMonsters == 5;
}

bool PlayerField::isFullSpellTraps() {
    return m_numSpellTraps == 5;
}

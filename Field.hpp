#pragma once

#include "Card.hpp"

class Field {
private:
    Card* field[5]= {0};

public:
    Field();

    void addCard(Card* card){
        for (int i = 0; i<5; i++){
            if (field[i] == nullptr) {
                field[i] = card;
                break;
            }
        }
    }

    void removeCard(Card* card) {
        for (int i = 0; i<5; i++){
            if (field[i] == card) {
                field[i] = nullptr;
                break;
            }
        }
    }

    
};

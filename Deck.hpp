#pragma once

#include <vector>
#include <algorithm>

#include "Card.hpp"
#include "Cards.cpp"


#define MAX_DECK_SIZE 60
#define MIN_DECK_SIZE 40

class Deck {
private:
    std::vector<Card*> cards;

public:
    Deck(std::vector<Card*> c) : cards(c) {
        if (MIN_DECK_SIZE <= cards.size() && cards.size() <= MAX_DECK_SIZE) {
            shuffle();
            return;
        }
        std::cout << "Decks size is not what we want (" << cards.size() << ")\n";
        exit(23); //temporary
    }

    void shuffle() {
        std::random_shuffle(cards.begin(), cards.end());
    }

    Card* drawCard() {
        Card* card = cards.back();
        cards.pop_back();
        return card;
    }

    bool isEmpty() {
        return cards.empty();
    }

};
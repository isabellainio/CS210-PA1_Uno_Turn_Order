#pragma once

#include <ostream>
#include <iostream>
#include <string>
#include "Stack.h"
#include "Card.h"

class Player {
public:
    Player(int id, const std::string& name)
        : id_(id), name_(name) {}

    bool operator==(const Player& other) const {
        return id_ == other.id_;
    }

    friend std::ostream& operator<<(std::ostream& out, const Player& p) {
        return out << p.id_ << " " << p.name_;
    }

    void addCard(Card* card) {
        hand_.push(card);
    }

    void playCard() {
        Card* card = hand_.pop();

        if (card != nullptr) {
            std::cout << name_ << " plays " << *card << std::endl;
            delete card;
        }
    }

    void printHand() const {
        hand_.print();
    }

private:
    int id_;
    std::string name_;
    Stack<Card> hand_;
};
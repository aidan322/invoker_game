#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include "card.hpp"

class Player {
private:
    int id;
    int defCoef = 0;
    int skipCount = 0;
    std::vector<std::unique_ptr<Card>> handCharacters;
    std::vector<std::vector<std::unique_ptr<Card>>> field; // 2 x 4 slots
public:
    Player(int _id = 0) : id(_id) {
        field.resize(2);
        for(int i=0;i<2;i++){
            field[i].resize(4);
            for(int j=0;j<4;j++){
                field[i][j] = std::make_unique<CharacterCard>("EmptySlot", 0,0,0,0);
            }
        }
    }
    int getId() const { return id; }
    void addCharacterToHand(std::unique_ptr<Card> c) { handCharacters.push_back(std::move(c)); }
    bool isFieldFull() const {
        for(int i=0;i<2;i++) for(int j=0;j<4;j++) if(field[i][j]->getType()=="EmptySlot") return false;
        return true;
    }
    void moveCardToField(std::unique_ptr<Card> newCard, int row, int col) {
        field[row][col] = std::move(newCard);
    }
    std::string getCardType(int row, int col) const { return field[row][col]->getType(); }
    void printField(bool reverse=false) const {
        std::cout << "Field (Player " << id << "):\\n";
        for(int i=0;i<2;i++){
            for(int j=0;j<4;j++) std::cout << field[i][j]->getType() << " ";
            std::cout << "\\n";
        }
    }
};

#endif // PLAYER_HPP

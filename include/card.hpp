#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <iostream>

class Player; // forward

class Card {
protected:
    std::string type;
public:
    Card(const std::string& t) : type(t) {}
    virtual ~Card() = default;
    std::string getType() const { return type; }
    virtual void activate(Player& owner, Player& opponent, int row) = 0;
    virtual void activateAI(Player& owner, Player& opponent, int row) = 0;
    virtual void printInfo() const = 0;
};

class CharacterCard : public Card {
private:
    int health;
    int damage;
    int healAmount;
    int defenseBonus;
    bool reflection;
public:
    CharacterCard(const std::string& t, int hp=0, int dmg=0, int heal=0, int def=0)
        : Card(t), health(hp), damage(dmg), healAmount(heal), defenseBonus(def), reflection(false) {}
    virtual ~CharacterCard() = default;

    void activate(Player& owner, Player& opponent, int row) override {
        std::cout << "Character " << type << " activated (default)\\n";
    }
    void activateAI(Player& owner, Player& opponent, int row) override {
        std::cout << "AI activated character " << type << "\\n";
    }
    void printInfo() const override {
        std::cout << "Character: " << type << " HP:" << health << " DMG:" << damage << "\\n";
    }
    int getHealth() const { return health; }
    int getDamage() const { return damage; }
    int getHealAmount() const { return healAmount; }
    int getDefenseBonus() const { return defenseBonus; }
    bool getReflection() const { return reflection; }
    void setReflection() { reflection = true; }
    void takeDamage(int d) { if(!reflection) health -= d; else reflection = false; }
    void heal(int a) { health += a; }
};

class AbilityCard : public Card {
public:
    AbilityCard(const std::string& t) : Card(t) {}
    virtual ~AbilityCard() = default;
    void activate(Player& owner, Player& opponent, int row) override {
        std::cout << "Ability " << type << " used\\n";
    }
    void activateAI(Player& owner, Player& opponent, int row) override {
        std::cout << "AI used ability " << type << "\\n";
    }
    void printInfo() const override {
        std::cout << "Ability: " << type << "\\n";
    }
};

#endif // CARD_HPP

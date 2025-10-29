#ifndef CLASSIC_MODE_HPP
#define CLASSIC_MODE_HPP

#include "gamemode.hpp"

class ClassicMode : public GameMode {
public:
    std::string name() const override { return "Classic Mode"; }

    void start(Invoker& invoker) override {
        std::cout << "--- Classic Mode ---\n";
        invoker.listSpells();
        std::string spell;
        while (true) {
            std::cout << "Enter spell name (or 'exit'): ";
            std::cin >> spell;
            if (spell == "exit") break;
            invoker.castSpell(spell);
        }
    }
};

#endif

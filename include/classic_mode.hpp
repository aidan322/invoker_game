#ifndef CLASSIC_MODE_HPP
#define CLASSIC_MODE_HPP

#include "gamemode.hpp"
#include <algorithm>

class ClassicMode : public GameMode {
public:
    std::string name() const override { return "Classic Mode"; }

    void start(Invoker& invoker) override {
        std::cout << "--- Classic Mode ---\n";
        invoker.listSpells();
        std::string combo;

        while (true) {
            std::cout << "Enter combo (or 'exit'): ";
            std::cin >> combo;
            if (combo == "exit") break;


            combo.erase(std::remove_if(combo.begin(), combo.end(), ::isspace), combo.end());
            std::transform(combo.begin(), combo.end(), combo.begin(), ::toupper);

            bool found = false;
            for (const auto& name : invoker.getAllSpellNames()) {
                if (invoker.getComboByName(name) == combo) {
                    invoker.castSpell(name);
                    found = true;
                    break;
                }
            }

            if (!found)
                std::cout << "> (unknown combo: " << combo << ")\n";
        }
    }
};

#endif
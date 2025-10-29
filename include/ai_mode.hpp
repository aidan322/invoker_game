#ifndef AI_MODE_HPP
#define AI_MODE_HPP

#include "gamemode.hpp"
#include <thread>
#include <chrono>
#include <cstdlib>

class AIMode : public GameMode {
public:
    std::string name() const override { return "AI Mode"; }

    void start(Invoker& invoker) override {
        std::cout << "--- AI Mode ---\n";
        invoker.listSpells();

        int playerScore = 0, aiScore = 0;

        for (int i = 0; i < 5; ++i) {
            std::string spell;
            std::cout << "Round " << i + 1 << ": ";
            std::cout << "Enter spell: ";
            std::cin >> spell;

            invoker.castSpell(spell);
            playerScore++;

            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            std::cout << "AI casts faster!\n";
            aiScore++;
        }

        std::cout << "\nResult: ";
        if (playerScore >= aiScore) std::cout << "You win!\n";
        else std::cout << "AI wins!\n";
    }
};

#endif

#include <iostream>
#include <memory>
#include "game.hpp"
#include "rank_mode.hpp"
#include "classic_mode.hpp"
#include "ai_mode.hpp"
#include "invoker.hpp"

int main() {
    Invoker invoker;
    invoker.addSpell(std::make_unique<Spell>("cold_snap", "Q Q Q"));
    invoker.addSpell(std::make_unique<Spell>("ghost_walk", "Q Q W"));
    invoker.addSpell(std::make_unique<Spell>("ice_wall", "Q Q E"));
    invoker.addSpell(std::make_unique<Spell>("emp", "W W W"));
    invoker.addSpell(std::make_unique<Spell>("tornado", "W W Q"));
    invoker.addSpell(std::make_unique<Spell>("alacrity", "W W E"));
    invoker.addSpell(std::make_unique<Spell>("sun_strike", "E E E"));
    invoker.addSpell(std::make_unique<Spell>("forge_spirit", "E E Q"));
    invoker.addSpell(std::make_unique<Spell>("chaos_meteor", "E E W"));
    invoker.addSpell(std::make_unique<Spell>("deafening_blast", "Q W E"));

    Game game;

    while (true) {
        std::cout << "\nSelect mode:\n";
        std::cout << "1. Rank Mode\n";
        std::cout << "2. Classic Mode\n";
        std::cout << "3. AI Mode\n";
        std::cout << "0. Exit\n";
        std::cout << "> ";

        int choice;
        std::cin >> choice;

        if (choice == 0) break;
        else if (choice == 1) game.setMode(std::make_unique<RankMode>());
        else if (choice == 2) game.setMode(std::make_unique<ClassicMode>());
        else if (choice == 3) game.setMode(std::make_unique<AIMode>());
        else {
            std::cout << "Invalid option.\n";
            continue;
        }

        game.start(invoker);
    }

    std::cout << "Goodbye!\n";
    return 0;
}

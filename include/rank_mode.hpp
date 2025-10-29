#ifndef RANK_MODE_HPP
#define RANK_MODE_HPP

#include "gamemode.hpp"
#include "invoker.hpp"
#include <chrono>
#include <algorithm>
#include <random>
#include <iostream>

/**
 * RankMode:
 *  - берётся список всех заклинаний invoker'а,
 *  - порядок перемешивается случайно,
 *  - игрок по очереди видит имя заклинания и вводит комбинацию орбов (Q/W/E),
 *  - программа не "наказывает" за ошибку — просто продолжает (как оригинал),
 *  - в конце засекается общее время и выводится ранг.
 */
class RankMode : public GameMode {
public:
    std::string name() const override { return "Rank Mode"; }

    void start(Invoker& invoker) override {
        std::cout << "--- Rank Mode ---\n";
        std::cout << "Invoke all spells as fast as you can!\n";
        std::cout << "You will be shown spell names one by one. For each, type the orb combo (Q/W/E), e.g. QWE or q w e.\n";
        std::cout << "Misses are allowed (they are ignored) — just try to be fast and accurate.\n\n";

        // get all spells
        auto spellNames = invoker.getAllSpellNames();
        if (spellNames.empty()) {
            std::cout << "No spells available in invoker. Add spells before starting.\n";
            return;
        }

        // shuffle (random order)
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(spellNames.begin(), spellNames.end(), g);

        // start timer
        auto t0 = std::chrono::high_resolution_clock::now();

        // for each target spell: show name, read combo, validate (but do not penalize)
        for (size_t i = 0; i < spellNames.size(); ++i) {
            const std::string& target = spellNames[i];

            std::cout << "Spell #" << (i + 1) << ": " << target << "\n";
            std::cout << "Enter combo: ";
            std::string input;
            // read a full line (to accept spaces)
            std::getline(std::cin >> std::ws, input);

            bool ok = invoker.validateComboByName(target, input);
            if (ok) {
                std::cout << "  -> OK\n";
                invoker.castSpell(target);
            } else {
                std::cout << "  -> Wrong (ignored)\n";
            }
        }

        auto t1 = std::chrono::high_resolution_clock::now();
        double seconds = std::chrono::duration<double>(t1 - t0).count();

        std::cout << "\nTotal time: " << seconds << " sec\n";

        // ranks:
        if (seconds > 25.0) std::cout << "Rank: Herald\n";
        else if (seconds > 20.0) std::cout << "Rank: Guardian\n";
        else if (seconds > 15.0) std::cout << "Rank: Crusader\n";
        else if (seconds > 10.0) std::cout << "Rank: Archon\n";
        else if (seconds > 9.0) std::cout << "Rank: Legend\n";
        else if (seconds > 8.0) std::cout << "Rank: Ancient\n";
        else if (seconds > 7.0) std::cout << "Rank: Divine\n";
        else std::cout << "Rank: Immortal\n";

        std::cout << "\nRank Mode finished.\n";
    }
};

#endif // RANK_MODE_HPP
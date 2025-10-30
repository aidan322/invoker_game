#ifndef AI_MODE_HPP
#define AI_MODE_HPP

#include "gamemode.hpp"
#include "invoker.hpp"
#include <chrono>
#include <iostream>
#include <string>
#include <cmath>

/**
 * AIMode — тренировочный режим тайминга прокаста:
 * Игрок сам кастует Tornado (QWWR) и затем Sun Strike (EEER).
 * ИИ (ассистент) измеряет время между кастами и оценивает попадание по таймингу.
 *
 * Заметь: режим не требует реального raw ввода клавиш — всё через Enter,
 * поэтому корректно работает на любых системах/терминалах.
 */
class AIMode : public GameMode {
public:
    std::string name() const override { return "AI Timing Mode"; }

    void start(Invoker& invoker) override {
        std::cout << "--- AI Timing Mode (Tornado -> Sun Strike) ---\n\n";

        // Проверяем, что у инвокера есть нужные заклинания
        std::string tornadoName = "tornado";
        std::string sunName     = "sun_strike";

        if (invoker.getComboByName(tornadoName).empty() ||
            invoker.getComboByName(sunName).empty()) {
            std::cout << "Required spells not found in invoker. Make sure '" 
                      << tornadoName << "' and '" << sunName << "' are added.\n";
            return;
        }

        std::cout << "Goal: cast Sun Strike so that it lands when the Tornado lift ends.\n";
        std::cout << "Mechanics (simplified): Tornado lift = 2.2s, Sun Strike hit delay = 1.7s.\n";
        std::cout << "So ideal wait between Tornado and Sun Strike casts = 0.5s.\n\n";

        std::cout << "Instructions:\n";
        std::cout << "1) Type the Tornado combo (e.g. QWWR) and press Enter.\n";
        std::cout << "2) Wait and then type the Sun Strike combo (e.g. EEER) and press Enter.\n";
        std::cout << "   Try to make the time between the two Enters close to 0.5 seconds.\n";
        std::cout << "Press Enter to start...\n";
        std::string tmp;
        std::getline(std::cin, tmp);

        // --- Read Tornado ---
        std::cout << "Cast Tornado (type its combo then Enter): ";
        std::string input;
        std::getline(std::cin, input);
        // we don't enforce exact text like "QWWR" because invoker.validateComboByName checks by spell name
        // but we'll check using invoker.validateComboByName to be forgiving
        if (!invoker.validateComboByName(tornadoName, input)) {
            std::cout << "Warning: input did not match tornado combo. Continuing anyway (mode is tolerant).\n";
        }
        auto t_tornado = std::chrono::high_resolution_clock::now();
        std::cout << "Tornado cast recorded. (lift ~2.2s)\n";

        // Prompt for Sun Strike
        std::cout << "Now cast Sun Strike (type combo then Enter) at the right timing: ";
        std::string sunInput;
        std::getline(std::cin, sunInput);
        auto t_sun = std::chrono::high_resolution_clock::now();

        if (!invoker.validateComboByName(sunName, sunInput)) {
            std::cout << "Warning: input did not match sun strike combo. Result will still be evaluated based on timing.\n";
        }

        // Calculate delay between casts
        std::chrono::duration<double> diff = t_sun - t_tornado;
        double waited = diff.count(); // seconds

        // Ideal delta = 0.5s (2.2 - 1.7)
        const double ideal = 0.5;
        double delta = waited - ideal; // positive => too late, negative => too early
        double absdelta = std::abs(delta);

        // Output results
        std::cout << "\nYou waited: " << waited << " s\n";
        if (absdelta <= 0.1) {
            std::cout << "Result: PERFECT timing! (Δ = " << delta << " s)\n";
        } else if (absdelta <= 0.3) {
            if (delta < 0) std::cout << "Result: Slightly early (Δ = " << delta << " s)\n";
            else std::cout << "Result: Slightly late (Δ = " << delta << " s)\n";
        } else {
            if (delta < 0) std::cout << "Result: Too early (Δ = " << delta << " s)\n";
            else std::cout << "Result: Too late (Δ = " << delta << " s)\n";
        }

        std::cout << "\nAI note: ideal wait = " << ideal << " s (Tornado lift 2.2s, Sun Strike delay 1.7s).\n";
        std::cout << "Mode finished.\n\n";
    }
};

#endif // AI_MODE_HPP

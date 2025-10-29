#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <iostream>
#include "gamemode.hpp"

class Game {
private:
    std::unique_ptr<GameMode> mode;
public:
    void setMode(std::unique_ptr<GameMode> m) { mode = std::move(m); }
    void start(Invoker& invoker) {
        if (mode) mode->start(invoker);
        else std::cout << "No mode selected.\n";
    }
};

#endif

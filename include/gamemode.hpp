#ifndef GAMEMODE_HPP
#define GAMEMODE_HPP

#include <string>
#include "invoker.hpp"

class GameMode {
public:
    virtual ~GameMode() = default;
    virtual std::string name() const = 0;
    virtual void start(Invoker& invoker) = 0;
};

#endif

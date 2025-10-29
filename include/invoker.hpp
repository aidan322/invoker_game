#ifndef INVOKER_HPP
#define INVOKER_HPP

#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include <algorithm>
#include "spell.hpp"

/**
 * Invoker хранит набор известных заклинаний и умеет:
 *  - addSpell(std::unique_ptr<Spell>)
 *  - listSpells()
 *  - getAllSpellNames()
 *  - getComboByName(name)
 *  - validateComboByName(name, inputCombo)
 *  - castSpell(name)  (печатная имитация)
 */
class Invoker {
private:
    std::vector<std::unique_ptr<Spell>> spells_;
public:
    Invoker() = default;
    ~Invoker() = default;

    void addSpell(std::unique_ptr<Spell> s) {
        spells_.push_back(std::move(s));
    }

    void listSpells() const {
        std::cout << "Available spells:\n";
        for (const auto& s : spells_) {
            std::cout << " - " << s->getName() << " (" << s->getCombo() << ")\n";
        }
    }

    std::vector<std::string> getAllSpellNames() const {
        std::vector<std::string> res;
        for (const auto& s : spells_) res.push_back(s->getName());
        return res;
    }

    // возвращает комбинацию (например "QWE") для имени заклинания, или пустую строку если нет
    std::string getComboByName(const std::string& name) const {
        for (const auto& s : spells_) {
            if (s->getName() == name) return s->getCombo();
        }
        return std::string();
    }

    // проверяет, совпадает ли введённая комбинация с комбо заклинания name
    bool validateComboByName(const std::string& name, const std::string& inputCombo) const {
        for (const auto& s : spells_) {
            if (s->getName() == name) return s->matchesCombo(inputCombo);
        }
        return false;
    }

    // Печать "каста" — для имитации
    void castSpell(const std::string& name) const {
        for (const auto& s : spells_) {
            if (s->getName() == name) {
                std::cout << "> Casted: " << s->getName() << " (" << s->getCombo() << ")\n";
                return;
            }
        }
        std::cout << "> (unknown spell: " << name << ")\n";
    }
};

#endif // INVOKER_HPP
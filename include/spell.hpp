#ifndef SPELL_HPP
#define SPELL_HPP

#include <string>
#include <algorithm>

/**
 * Простая модель заклинания.
 * combo хранится в компактном виде без пробелов, например "QQQ", "QWE", "EEQ".
 */
class Spell {
private:
    std::string name_;
    std::string combo_; // "QQQ", "QWE", ...
public:
    Spell(const std::string& name = "", const std::string& combo = "")
        : name_(name), combo_(combo) {
        // Нормализуем combo: убираем пробелы и делаем заглавными
        std::string tmp;
        for (char c : combo_) {
            if (c != ' ' && c != '\t') tmp.push_back((char)std::toupper((unsigned char)c));
        }
        combo_ = tmp;
    }

    std::string getName() const { return name_; }
    std::string getCombo() const { return combo_; } // "QWE" и т.д.

    // Сравнить входную комбинацию (произвольный формат) с этим спеллом
    bool matchesCombo(const std::string& input) const {
        // нормализуем вход: убрать пробелы, сделать заглавными
        std::string tmp;
        for (char c : input) {
            if (c == 'q' || c == 'Q' || c == 'w' || c == 'W' || c == 'e' || c == 'E')
                tmp.push_back((char)std::toupper((unsigned char)c));
            // также игнорируем любые другие символы (например пробелы)
        }
        return tmp == combo_;
    }
};

#endif // SPELL_HPP
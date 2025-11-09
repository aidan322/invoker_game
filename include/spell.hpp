#ifndef SPELL_HPP
#define SPELL_HPP

#include <string>
#include <algorithm>

class Spell {
private:
    std::string name_;
    std::string combo_; // "QQQ", "QWE", ...
public:
    Spell(const std::string& name = "", const std::string& combo = "")
        : name_(name), combo_(combo) {
        std::string tmp;
        for (char c : combo_) {
            if (c != ' ' && c != '\t') 
                tmp.push_back((char)std::toupper((unsigned char)c));
        }
        combo_ = tmp;
    }

    std::string getName() const { return name_; }
    std::string getCombo() const { return combo_; }

    bool matchesCombo(const std::string& input) const {
    auto normalize = [](std::string s) {
        s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
        std::transform(s.begin(), s.end(), s.begin(), ::toupper);
        return s;
    };
    return normalize(input) == normalize(combo_);
    }

};

#endif // SPELL_HPP

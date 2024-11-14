#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"
#include <string>

class HumanA {
private:
    std::string name;
    Weapon& weapon;  // Reference since HumanA will always have a weapon

public:
    HumanA(const std::string& name, Weapon& weapon);
    void attack() const;
};

#endif

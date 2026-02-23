#include "HumanB.hpp"

HumanB::HumanB() : weapon(NULL), name("")
{
}

HumanB::HumanB(std::string name) : weapon(NULL), name(name)
{
}

HumanB::~HumanB()
{
}

void HumanB::attack() const
{
    if (!this->weapon)
        return;
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}


#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(&weapon)
{
    std::cout << &this->weapon << std::endl;
}

HumanA::~HumanA()
{
    std::cout << this->name << " Destructor Called" << std::endl;
}

void HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}
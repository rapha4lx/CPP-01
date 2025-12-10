#include "HumanA.hpp"

HumanA::HumanA() {}

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(&weapon), name(name)
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
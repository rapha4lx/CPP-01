#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug()
{
    std::cout << "Debug level complaint" << std::endl;
}

void Harl::info()
{
    std::cout << "Info level complaint" << std::endl;
}

void Harl::warning()
{
    std::cout << "Warning level complaint" << std::endl;
}

void Harl::error()
{
    std::cout << "Error level complaint" << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    void (Harl::*MemFunc[])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*MemFunc[i])();
            return;
        }
    }
}


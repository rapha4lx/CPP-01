#include <iostream>

class Harl
{
private:
    void debug();
    void info();
    void warning();
    void error();
public:
    Harl();
    ~Harl();
    void complain(std::string level);

};

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
    std::string levels[] = { "DEBUG", "INFO", "WARGING", "ERROR" };
    void(Harl::*MemFunc[])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

    for (int i = 0; i < 4; i++) 
    {
        if (levels[i] == level)
        {
            (this->*MemFunc[i])();
            return ;
        }
    }
}

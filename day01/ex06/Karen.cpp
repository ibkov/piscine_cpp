#include "Karen.hpp"

Karen::Karen()
{
    return ;
}

Karen::~Karen()
{
    return ;
}

void Karen::debug( void )
{
    std::cout << "I love to get extra bacon for my"
    " 7XL-double-cheese-triple-pickle-special-ketchup burger."
    " I just love it!\n";
}

void Karen::info( void )
{
    std::cout << "I cannot believe adding extra bacon cost more money. "
    "You don’t put enough! If you did I would not have to ask for it!\n";
}


void Karen::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. "
    "I’ve been coming here for years and you just started working here last month.\n";
}

void Karen::error( void )
{
    std::cout << "This is unacceptable, I want to speak to the manager now.\n";
}

void Karen::complain(std::string level)
{
    void (Karen::*functions)() = NULL;
    ((level.compare("DEBUG") == 0) && (functions = &Karen::debug));
    ((level.compare("WARNING") == 0) && (functions = &Karen::warning));
    ((level.compare("INFO") == 0) && (functions = &Karen::info));
    ((level.compare("ERROR") == 0) && (functions = &Karen::error));
    (this->*functions)();
}


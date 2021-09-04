#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
   std::cout << "<" << name << "> " << "died\n"; 
}

void Zombie::announce(void)
{
    std::cout << "<" << name << "> " << "BraiiiiiiinnnzzzZ...\n"; 
}
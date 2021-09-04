#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
    Zombie *new_Zombie = new Zombie(name);
    new_Zombie->announce();
    return (new_Zombie);
}
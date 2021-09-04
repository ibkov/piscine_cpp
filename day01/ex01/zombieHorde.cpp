#include "Zombie.hpp"

void Zombie::naming(std::string name)
{
    this->name = name;
}

Zombie *zombieHorde(int N, std::string name)
{
    Zombie *horde = new Zombie[N];
    for (int i = 0; i < N; i++)
        horde[i].naming(name);
    return horde;
}
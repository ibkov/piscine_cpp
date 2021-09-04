#include "Zombie.hpp"

int main()
{
    Zombie *firstZ = newZombie("firstZ");
    delete firstZ;
    randomChump("secondZ");
    return (0);
}
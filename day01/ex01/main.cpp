#include "Zombie.hpp"
#include <cstdlib>

int print_error()
{
    std::cout << "Your input is not correct!\n";
    return (1);
}

int main(int argc, char **argv)
{
    std::string name;
    int N;

    if (argc == 3)
    {
        if ((N = atoi(argv[1])) < 0)
            return print_error();
    }
    else 
        return print_error();
    name = argv[2];
    Zombie *zombie_horde = zombieHorde(N, name);
    for (int i = 0; i < N; i++)
        zombie_horde[i].announce();
    delete[] zombie_horde;
    return (0);
}
#include "Karen.hpp"

int main()
{
    std::string levels[4] = {"DEBUG", "ERROR", "WARNING", "INFO"};
    Karen new_obj;

    srand(time(0));
    new_obj.complain(levels[rand() % 4]);
    return (0);
}
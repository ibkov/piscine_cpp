#include "Karen.hpp"

int main(int argc, char **argv)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    Karen new_obj;
    int i = 0;
    std::string word;

    if (argc == 2)
    {
        word = argv[1];
        while((i < 4) && (levels[i].compare(word) != 0))
            i++;
        switch (i)
        {
        case 0:
            std::cout << "[DEBUG]\n";
            new_obj.complain("DEBUG");
            std::cout << std::endl;
        case 1:
            std::cout << "[INFO]\n";
            new_obj.complain("INFO");
            std::cout << std::endl;
        case 2:
            std::cout << "[WARNING]\n";
            new_obj.complain("WARNING");
            std::cout << std::endl;
        case 3:
            std::cout << "[ERROR]\n";
            new_obj.complain("ERROR");
            std::cout << std::endl;
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
            break;
        }
    }
    else
    {
        std::cerr << "Invalid arguments!!!\n";
        return (1);
    }
    return (0);
    
}
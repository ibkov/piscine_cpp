#include <iostream>
#include <string>

static void menu(void)
{
    std::cout << "\n***PHONEBOOK***\n";
    std::cout << std::endl;
    std::cout << "Use following commands:" << std::endl;
    std::cout << "\nADD | ";
    std::cout << "SEARCH | ";
    std::cout << "EXIT" << std::endl;
    std::cout << std::endl;
}

int add_new_number()
{

}

int search_number()
{
    
}

int work_with_book(std::string cmd)
{
    if (cmd == "ADD")
        add_new_number();
    else
        search_number();
}

int main()
{
    std::string cmd;

    menu();
    while (1)
    {
        std::cin >> cmd;
        if (cmd == "EXIT")
            break;
        else if (cmd == "ADD" || cmd == "SEARCH")
            work_with_book(cmd);
        else
        {
            std::cout << "\nError use following commands: ADD, SEARCH, EXIT" << std::endl;
        }
    }
    return (0);
}
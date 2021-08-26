#include "Contact.class.hpp"
#include "Phonebook.class.hpp"


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

int add_new_number(Phonebook *pb)
{
    static int index = 1;
    Contact new_contact = Contact();
    
    std::cout << "\n\033[33mEnter first name: ";
    std::cin >> new_contact.first_name;
    std::cout << "Enter last name: ";
    std::cin >> new_contact.last_name;
    std::cout << "Enter last nickname: ";
    std::cin >> new_contact.nickname;
    std::cout << "Enter phone number: ";
    std::cin >> new_contact.phone;
    std::cout << "Enter secret: ";
    std::cin >> new_contact.secret;
    std::cout << "\033[32m\nContact added\n\033[0m";
    std::cout << "\nUse following commands:" << std::endl;
    std::cout << "\nADD | ";
    std::cout << "SEARCH | ";
    std::cout << "EXIT" << std::endl;
    new_contact.index = index;
    pb->phonebook[(index - 1) % 8] = new_contact;
    index++;
    return (1);
}

void print_cut_str(std::string str)
{
    if (str.length() > 10)
        std::cout << std::right << std::setfill(' ') << std::setw(10) << str.substr(0,9).append(".") << "|";
    else
        std::cout << std::right << std::setfill(' ') << std::setw(10) << str << "|";
}

void search_number(Phonebook new_phonebook, int count)
{
    std::cout << "\033[36m---------------------------------------------" << std::endl;
    std::cout << "|" << std::right << std::setw(11) << "index|"
    << std::right << std::setw(11) << "first name|"
    << std::right << std::setw(11) << "last name|"
     << std::right << std::setw(11) << "nickname|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    for (int i = 0; i < count; i++)
    {
        std::cout  << "|" << std::right << std::setfill(' ') << std::setw(10) << new_phonebook.phonebook[i].index << "|";
        print_cut_str(new_phonebook.phonebook[i].first_name);
        print_cut_str(new_phonebook.phonebook[i].last_name);
        print_cut_str(new_phonebook.phonebook[i].nickname);
        std::cout << std::endl;
        std::cout << "---------------------------------------------\033[0m" << std::endl;;
    }
}

int main()
{
    Phonebook new_phonebook;
    std::string cmd;
    int count_numbers = 0;
    menu();
    while (1)
    {
        std::cin >> cmd;
        if (cmd == "EXIT")
            break;
        else if (cmd == "ADD" || cmd == "SEARCH")
        {
            if (cmd == "ADD")
                count_numbers += add_new_number(&new_phonebook);
            else
                search_number(new_phonebook, count_numbers);
        }
        else
        {
            std::cout << "\n\033[31mError use following commands: ADD, SEARCH, EXIT\033[0m" << std::endl;
        }
    }
    return (0);
}
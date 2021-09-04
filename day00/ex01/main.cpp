#include "Contact.class.hpp"
#include "Phonebook.class.hpp"

static void menu(void)
{
    std::cout << "Use following commands:" << std::endl;
    std::cout << "\nADD | ";
    std::cout << "SEARCH | ";
    std::cout << "EXIT\033[0m" << std::endl;
    std::cout << std::endl;
}

int add_new_number(Phonebook *pb, int c)
{
    static int index = 1;
    Contact new_contact = Contact();
    std::string temp;
    
    std::cout << "\n\033[33mEnter first name: ";
    std::cin >> temp;
    new_contact.setFirstName(temp);
    std::cout << "Enter last name: ";
    std::cin >> temp;
    new_contact.setLastName(temp);
    std::cout << "Enter last nickname: ";
    std::cin >> temp;
    new_contact.setNickName(temp);
    std::cout << "Enter phone number: ";
    std::cin >> temp;
    new_contact.setPhone(temp);
    std::cout << "Enter secret: ";
    std::cin >> temp;
    new_contact.setSecret(temp);
    std::cout << "\033[32m\nContact added\n\n\033[0m";
    new_contact.setIndex(index);
    pb->phonebook[(index - 1)] = new_contact;
    index++;
    if (index > 8)
        index = 1;
    if (c < 8)
        return (1);
    else
        return (0);
}

void print_cut_str(std::string str)
{
    if (str.length() > 10)
        std::cout << std::right << std::setfill(' ') << std::setw(10) << str.substr(0,9).append(".") << "|";
    else
        std::cout << std::right << std::setfill(' ') << std::setw(10) << str << "|";
}

void show_all_info(int index, Phonebook pb)
{
    std::string cin_str;
    int cin_index;

    while (1)
    {
        std::cout << "\033[0mEnter index contact or '-1' to exit \"SEARCH\": ";
        std::cin >> cin_str;
        if (cin_str == "-1")
            break;
        if (isdigit(cin_str[0]) && atoi(&cin_str[0]) > 0)
            cin_index = atoi(&cin_str[0]);
        else
            cin_index = 10; 
        if (cin_index <= index)
        {
            std::cout << "Index: " << pb.phonebook[cin_index - 1].getIndex() << std::endl;
            std::cout << "First name: " << pb.phonebook[cin_index - 1].getFirstName() << std::endl;
            std::cout << "Last name: " << pb.phonebook[cin_index - 1].getLastName() << std::endl;
            std::cout << "Nickname: " << pb.phonebook[cin_index - 1].getNickName() << std::endl;
            std::cout << "Phone: " << pb.phonebook[cin_index - 1].getPhone() << std::endl;
            std::cout << "Darkest secret: " << pb.phonebook[cin_index - 1].getSecret() << std::endl;
        }
        else
            std::cout << "\n\033[31mThis index was not exist. Correct your input.\n\033[0m" << std::endl;
    }
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
        std::cout  << "|" << std::right << std::setfill(' ') << std::setw(10) << new_phonebook.phonebook[i].getIndex() << "|";
        print_cut_str(new_phonebook.phonebook[i].getFirstName());
        print_cut_str(new_phonebook.phonebook[i].getLastName());
        print_cut_str(new_phonebook.phonebook[i].getNickName());
        std::cout << std::endl;
        std::cout << "---------------------------------------------" << std::endl;;
    }
    show_all_info(count, new_phonebook);
}

int main()
{
    Phonebook new_phonebook;
    std::string cmd;
    int cn = 0;
    std::cout << "\033[32m\n***PHONEBOOK***\n\033[0m";
    std::cout << std::endl;
    while (1)
    {
        menu();
        std::cin >> cmd;
        if (cmd == "EXIT")
            break;
        else if (cmd == "ADD" || cmd == "SEARCH")
        {
            if (cmd == "ADD")
                cn += add_new_number(&new_phonebook, cn);
            else
                search_number(new_phonebook, cn);
        }
        else
        {
            std::cout << "\n\033[31mError! ";
        }
    }
    return (0);
}
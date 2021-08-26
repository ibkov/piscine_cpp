#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact{

public:
    int index;
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone;
    std::string secret;
    Contact( void );
    ~Contact( void );
};

#endif
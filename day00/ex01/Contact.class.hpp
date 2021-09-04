#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact{

private:
    int index;
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone;
    std::string secret;
public:
    Contact( void );
    ~Contact( void );
    int getIndex();
    std::string getFirstName();
    std::string getLastName();
    std::string getNickName();
    std::string getPhone();
    std::string getSecret();
    void setFirstName(std::string str);
    void setLastName(std::string str);
    void setNickName(std::string str);
    void setPhone(std::string str);
    void setSecret(std::string str);
    void setIndex(int nbr);

    
};

#endif
#include "Contact.class.hpp"

Contact::Contact( void )
{
   return ;
}

Contact::~Contact( void )
{
    return ;
}

void Contact::setFirstName(std::string str)
{
    this->first_name = str;
}

void Contact::setLastName(std::string str)
{
    this->last_name = str;
}

void Contact::setNickName(std::string str)
{
    this->nickname = str;
}

void Contact::setPhone(std::string str)
{
    this->phone = str;
}

void Contact::setSecret(std::string str)
{
    this->secret = str;
}

void Contact::setIndex(int nbr)
{
    this->index = nbr;
}

int Contact::getIndex()
{
    return index;
}

std::string Contact::getFirstName()
{
    return first_name;
}

std::string Contact::getLastName()
{
    return last_name;
}

std::string Contact::getNickName()
{
    return nickname;
}

std::string Contact::getPhone()
{
    return phone;
}

std::string Contact::getSecret()
{
    return secret;
}
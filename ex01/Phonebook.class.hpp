#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "Contact.class.hpp"
#include <vector>
#include <iostream>

class Phonebook
{
    public:
        Phonebook( void );
        Contact phonebook[8];
};

#endif
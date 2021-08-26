#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "Contact.class.hpp"

class Phonebook
{
    public:
        Phonebook( void );
        ~Phonebook( void );
        Contact phonebook[8];
};

#endif
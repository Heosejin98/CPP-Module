
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact  phone_info[8];
    int        index;
public:
    PhoneBook();
    ~PhoneBook();
    void add();
    bool search();
};

#endif

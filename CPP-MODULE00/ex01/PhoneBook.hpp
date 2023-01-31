
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include "PhoneInfo.hpp"

class PhoneBook
{
private:
    PhoneInfo  phone_info[8];
    int        index;
public:
    PhoneBook();

    ~PhoneBook();
    void add();
    void search();
};

#endif

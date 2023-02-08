#include <iostream>
#include <iomanip>

#include "Contact.hpp"

Contact::Contact()
{
    std::cout << std::setw(15) << "[Contact] " << "create!!" << std::endl;
    first_name = "";
    last_name = "";
    nickname = "";
    phone_number = "";
    darkest_secret = "";
}

void Contact::setPhone_info(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->nickname = nickname;
    this->phone_number = phone_number;
    this->darkest_secret = darkest_secret;
}

static void print_bar()
{
    for(int i = 0; i < 51; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
}

std::string limitString(const std::string &str)
{
    if (str.length() > 10)
    {
        return str.substr(0, 9) + ".";
    }
    return str;
}

void   Contact::view_info(int idx)
{
    print_bar();

    std::cout << "|" << std::setw(5) << idx+1 << "|" 
        << std::setw(10) << limitString(first_name) << '|'
        << std::setw(10) << limitString(last_name) << '|' 
        << std::setw(10) << limitString(nickname) << '|'
        << std::setw(10) << limitString(phone_number) << "|" << std::endl;  
}


void   Contact::search_info(int idx)
{
    std::cout <<  std::setw(20) << "index : " << std::setw(10) << idx+1 << std::endl;
    std::cout << std::setw(20) << "first name : " << std::setw(10) << limitString(first_name) << std::endl;
    std::cout << std::setw(20) << "last name : "  << std::setw(10) << limitString(last_name) << std::endl; 
    std::cout << std::setw(20) << "nick name : "  << std::setw(10) << limitString(nickname) << std::endl;
    std::cout << std::setw(20) << "phone number : " <<std::setw(10) << limitString(phone_number) << std::endl;  
}

Contact::~Contact()
{
    std::cout << std::setw(15) << "[Contact] " << "delete!!" << std::endl;
}



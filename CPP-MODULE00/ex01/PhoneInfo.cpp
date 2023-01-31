#include <iostream>
#include <iomanip>

#include "PhoneInfo.hpp"

PhoneInfo::PhoneInfo()
{
    std::cout << std::setw(15) << "[PhoneInfo] " << "create!!" << std::endl;
    first_name = "";
    last_name = "";
    nickname = "";
    phone_number = "";
    darkest_secret = "";
}

void PhoneInfo::setPhone_info(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
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
    if (str.length() > 9)
    {
        return str.substr(0, 9) + ".";
    }
    return str;
}

void   PhoneInfo::view_info(int idx)
{
    print_bar();
    // 한줄에 하나씩 출력 
    std::cout << "|" << std::setw(5) << idx+1 << "|" 
        << std::setw(10) << limitString(first_name) << '|'
        << std::setw(10) << limitString(last_name) << '|' 
        << std::setw(10) << limitString(nickname) << '|'
        << std::setw(10) << limitString(phone_number) << "|" << std::endl;  
}

PhoneInfo::~PhoneInfo()
{
    std::cout << std::setw(15) << "[PhoneInfo] " << "delete!!" << std::endl;
}


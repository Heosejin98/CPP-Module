#include <iostream>
#include <iomanip>

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    std::cout << std::setw(15) << "[PhoneBook] " << "create!!" << std::endl;
    index = 0;
}

void PhoneBook::add()
{
    std::string first_name = "";
    std::string last_name = "";
    std::string nickname = "";
    std::string phone_number = "";
    std::string darkest_secret = "";
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "first name : ";
    std::getline(std::cin, first_name);

    std::cout << "last name : ";
    std::getline(std::cin, last_name);


    std::cout << "nick name : ";
    std::getline(std::cin, nickname);


    std::cout << "phone number : ";
    std::getline(std::cin, phone_number);


    std::cout << "darkest secret : ";
    std::getline(std::cin, darkest_secret);

    
    this->phone_info[index].setPhone_info(first_name, last_name, nickname, phone_number, darkest_secret);
    this->index++;

    std::cout << first_name << last_name << "등록 완료" << std::endl;
    if (this->index > 7)
        this->index = 0;
}

static void print_bar()
{
    for(int i = 0; i < 51; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
}

void print_field()
{ 
    print_bar();
    std::cout << "|" << std::setw(5) << "index" << '|'
    << std::setw(10) << "FirstName" << '|'
    << std::setw(10) << "LastName" << '|' 
    << std::setw(10) << "NickName" << '|'
    << std::setw(10) << "PhoneNum" <<  "|" << std::endl;
}

void PhoneBook::search()
{
    int find_idx;

    print_field();
    for (int i = 0; i < 8; i++){
        phone_info[i].view_info(i);
    }
    print_bar();

    std::cout << "출력할 인덱스를 입력하세요 :";
    std::cin >> find_idx;
    print_field();
    phone_info[find_idx - 1].view_info(find_idx - 1);
    print_bar();
}

PhoneBook::~PhoneBook()
{
    std::cout << std::setw(15) << "[PhoneBook] " << "delete!!" << std::endl;
}


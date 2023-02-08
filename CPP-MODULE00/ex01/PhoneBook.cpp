#include <iostream>
#include <iomanip>

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    std::cout << std::setw(15) << "[PhoneBook] " << "create!!" << std::endl;
    index = 0;
}

static void check_input(std::string *input, std::string msg)
{
    while (*input == "") {
        std::cout << "입력하세요";
        std::cout << msg << " : ";
        std::getline(std::cin, *input);
    }
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
    check_input(&first_name, "first name");

    std::cout << "last name : ";
    std::getline(std::cin, last_name);
    check_input(&last_name, "last name");

    std::cout << "nick name : ";
    std::getline(std::cin, nickname);
    check_input(&nickname, "nick name");

    std::cout << "phone number : ";
    std::getline(std::cin, phone_number);
    check_input(&phone_number, "phone number");

    std::cout << "darkest secret : ";
    std::getline(std::cin, darkest_secret);
    check_input(&darkest_secret, "darkest secret");
    
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

bool isNumber(std::string str)
{
    for (unsigned long i = 0; i < str.length(); i++) {
        if (isdigit(str[i]) == 0) {
            return false;
        }
    }
    return true;
}

int search_index()
{
    std::string find_idx;

    print_bar();
    std::cout << "출력할 인덱스를 입력하세요 :";
    std::cin >> find_idx;

    if (std::cin.eof() == true) {
        return (-1);
    }
    
    if (isNumber(find_idx) && (std::stoi(find_idx) >= 1 && std::stoi(find_idx) <= 8)) {
        return std::stoi(find_idx);
    } else {
        std::cout << "1 ~ 8사이의 인덱스를 입력하세요" << std::endl;
        return search_index();
    }
}

bool PhoneBook::search()
{
    
    int contact_index;

    print_field();
    for (int i = 0; i < 8; i++){
        phone_info[i].view_info(i);
    }

    contact_index = search_index();

    if (contact_index == -1) {
        return (false);
    }

    phone_info[contact_index - 1].search_info(contact_index - 1);;
    return (true);
}

PhoneBook::~PhoneBook()
{
    std::cout << std::setw(15) << "[PhoneBook] " << "delete!!" << std::endl;
}


#include "PhoneBook.hpp"

std::string toUpperCase(std::string str)
{
    std::string res = "";

    for (int i = 0; str[i]; i++) {
        res += ((char) toupper(str[i]));
    }

    return res;
}

int main()
{
    PhoneBook phone_book;
    std::string input;

    while (true) {
        std::cout << "커맨드를 입력하세요 (1.ADD, 2.SEARCH 3.EXIT)" << std::endl;
        std::cin >> input;
        input = toUpperCase(input);
        if (input.compare("ADD") == 0) {
            phone_book.add();
        } else if (input.compare("SEARCH") == 0) {
            if (!phone_book.search()) {
                std::cout << "\nEXIT" << std::endl;
                break ;
            }
        } else if (input.compare("EXIT") == 0 || std::cin.eof() == true) {
            std::cout << "EXIT" << std::endl;
            break;
        } else {
            std::cout << "NOT FOUND COMMAND" << std::endl;
        }
    }
    return 0;
}

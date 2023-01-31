
#ifndef PHONEINFO_HPP
# define PHONEINFO_HPP
#include <iostream>
#include <string>


class PhoneInfo
{
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
public:
    PhoneInfo();
    ~PhoneInfo();
    void    setPhone_info(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret);
    void    view_info(int idx);
};


#endif

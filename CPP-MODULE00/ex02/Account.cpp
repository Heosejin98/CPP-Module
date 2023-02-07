#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account(int initial_deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _nbAccounts << ";amount:" << initial_deposit << ";created" << std::endl;
    this->_accountIndex = _nbAccounts++;
    this->_amount = initial_deposit;
    _totalAmount += this->_amount;
}


void	Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
              << ";total:" << _totalAmount 
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";deposits:" << this->_nbDeposits
              << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << this->_amount
              << ";deposit:" << deposit
              << ";amount:" << this->_amount + deposit 
              << ";nb_deposits:" << ++this->_nbDeposits << std::endl;
    this->_amount += deposit;
    this->_totalAmount += deposit;
    this->_totalNbDeposits++;
}

void	Account::_displayTimestamp( void )
{
    char buf[18];
    time_t curtime;
    struct tm *timeinfo;

    time(&curtime);
    timeinfo = localtime(&curtime);
    strftime(buf, 18, "[%Y%m%d_%H%M%S]",timeinfo);
    std::cout << buf << ' ' ;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();

    if (this->_amount - withdrawal >= 0) {
        std::cout << "index:" << this->_accountIndex
                << ";p_amount:" << this->_amount
                << ";withdrawal:" << withdrawal
                << ";amount:" << this->_amount - withdrawal 
                << ";nb_withdrawals:" << ++this->_nbWithdrawals << std::endl;
        this->_amount -= withdrawal;
        this->_totalAmount -= withdrawal;
        this->_totalNbWithdrawals++;

        return true;
    } else {
        std::cout << "index:" << this->_accountIndex
            << ";p_amount:" << this->_amount
            << ";withdrawal:refused" << std::endl;
        
        return false;
    }
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

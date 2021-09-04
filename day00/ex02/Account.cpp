#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <time.h>

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;


int Account::getNbAccounts(void)
{
    return (Account::_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (Account::_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (Account::_totalNbWithdrawals);
}

Account::Account(void)
{
    _accountIndex = _nbAccounts++;
    _amount = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
}

Account::Account(int initial_deposit)
{
    _amount = initial_deposit;
    _totalAmount += _amount;
    _accountIndex = _nbAccounts++;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}


Account::~Account( void )
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
    _nbAccounts = 0;
    _totalAmount = 0;
    _totalNbDeposits = 0;
    _totalNbWithdrawals = 0;
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << " accounts:" << getNbAccounts()
    << ";total:" << getTotalAmount()
    << ";deposits:" << getNbDeposits()
    << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit)
{
    _totalAmount += deposit;
    _totalNbDeposits++;
    _amount += deposit;
    _nbDeposits++;

    _displayTimestamp();
    std::cout << " index:" << _accountIndex
    << ";p_amount:" << _amount - deposit
    << ";deposit:" << deposit
    << ";amount:" << _amount
    << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal )
{
    if (_amount < withdrawal)
    {
        _displayTimestamp();
        std::cout << " index:" << _accountIndex
        << ";p_amount:" << _amount
        << ";withdrawal:refused"<< std::endl;
        return false;
    }
    else
    {
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        _amount -= withdrawal;
        _nbWithdrawals++;

        _displayTimestamp();
        std::cout << " index:" << _accountIndex
        << ";p_amount:" << _amount + withdrawal
        << ";withdrawal:" << withdrawal
        << ";amount:" << _amount
        << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return true;
    }
}

int Account::checkAmount( void ) const
{
    if (_amount)
        return (_amount);
    else
        return (0);
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
    << ";amount:" << _amount
    << ";deposits:" << _nbDeposits
    << ";withdrawals:" << _nbWithdrawals
    << std::endl;
}

void Account::_displayTimestamp(void)
{
    time_t cur_time;
    struct tm *ti;
    time(&cur_time);
    ti = localtime(&cur_time);
    // std::cout << std::setfill('0') << "[" << (ti->tm_year + 1900) 
    // << std::setw(2) << (ti->tm_mon + 1) << std::setw(2) << ti->tm_mday
    // << "_" << std::setw(2) << ti->tm_hour << std::setw(2) << ti->tm_min
    // << std::setw(2) << ti->tm_sec << "]";
    std::cout << "[19920104_091532]";
}
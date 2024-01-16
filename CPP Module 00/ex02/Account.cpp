#include "Account.hpp"
#include <iostream>
#include <time.h>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account()
{
}

Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_totalAmount += _amount;
	_accountIndex = _nbAccounts;
	_displayTimestamp();
	std::cout << "index:" << _nbAccounts++ << ";"
	<< "amount:" << initial_deposit << ";"
	<< "created" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}
int	Account::getTotalAmount(void)
{
	return _totalAmount;
}
int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}
int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
	<< "total:" << getTotalAmount() << ";"
	<< "deposits:" << getNbDeposits() << ";"
	<< "withdrawals:" << getNbWithdrawals()
	<< "\n" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	if (_accountIndex == 0)
		std::cout << std::endl;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
	<< "p_amount:" << _amount << ";"
	<< "deposit:" << deposit << ";";
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << "amount:" << _amount << ";";
	if (deposit != 0)
		_nbDeposits++;
	_totalNbDeposits += _nbDeposits;
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}
bool	Account::makeWithdrawal(int withdrawal)
{
	if (_accountIndex == 0)
		std::cout << std::endl;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
	<< "p_amount:" << _amount << ";";
	if (withdrawal > checkAmount())
	{
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	_totalNbWithdrawals += ++_nbWithdrawals;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << "withdrawal:" << withdrawal << ";"
	<< "amount:" << _amount << ";"
	<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int		Account::checkAmount(void) const
{
	return _amount;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
	<< "amount:" << _amount << ";"
	<< "deposits:" << _nbDeposits << ";"
	<< "withdrawals:" << _nbWithdrawals
	<< std::endl;	
}

void	Account::_displayTimestamp(void)
{
	time_t 			timer;
	struct tm 		*tmstamp;
	char			tmstamp_buffer[100];
	
	time(&timer);
	tmstamp = localtime(&timer);
	strftime(tmstamp_buffer, 100, "[%G%m%d_%H%M%S] ", tmstamp);
	std::cout << tmstamp_buffer;
}

Account::~Account(void)
{
	if (_accountIndex == 0) std::cout << "\n";
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
	<< "amount:" << _amount << ";"
	<< "closed" << std::endl;
}

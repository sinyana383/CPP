#include "Account.hpp"
#include <iostream>
#include <iomanip>

// Static ///////////////////////////////////////
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp()
{
	std::time_t curTime = std::time(nullptr);
	std::cout << std::put_time(std::localtime(&curTime), "[%Y%m%d_%H%M%S] ");
}

int Account::getNbAccounts(){ return (Account::_nbAccounts); }
int Account::getTotalAmount(){ return (Account::_totalAmount); }
int Account::getNbDeposits(){ return (Account::_totalNbDeposits); }
int Account::getNbWithdrawals(){ return (Account::_totalNbWithdrawals); }

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount()  << ";";
	std::cout << "deposits:" << getNbDeposits()  << ";";
	std::cout << "withdrawals:" << getNbWithdrawals()  << std::endl;

}

// ///////////////////////////////////////////////

int Account::checkAmount() const { return (_amount); }

Account::Account(int initial_deposit) : _amount(initial_deposit),  _nbDeposits(0), _nbWithdrawals(0)
{
	_accountIndex = Account::getNbAccounts();	// пока кол-во на один меньше
	Account::_totalAmount += checkAmount();
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "created" << std::endl;
	++Account::_nbAccounts;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << checkAmount() << ";";	// check_amount?
	std::cout << "closed" << std::endl;
	--Account::_nbAccounts;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl; // check_amount?
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << checkAmount() << ";";
	std::cout << "deposit:" << deposit << ";";
	_amount += deposit;
	Account::_totalAmount += deposit;
	++Account::_totalNbDeposits;
	++_nbDeposits;
	std::cout << "amount:" << checkAmount() << ";"; // check_amount?
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool 	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "withdrawal:";
	if (checkAmount() < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal << ";";
	_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	std::cout << "amount:" << _amount << ";";
	++_nbWithdrawals;
	++Account::_totalNbWithdrawals;
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

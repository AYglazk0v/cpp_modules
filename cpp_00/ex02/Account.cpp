#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_nbAccounts = 0;

Account::Account(void) {};

Account::Account(int initial_desposit) {
	Account::_amount = initial_desposit;
	Account::_nbDeposits = 0;
    Account::_nbWithdrawals = 0;
	Account::_accountIndex = Account::_nbAccounts++;
	Account::_totalAmount = Account::_totalAmount + initial_desposit;
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex
				<< ";amount:" << Account::_amount
				<< ";created" << std::endl;
};

Account::~Account(void) {
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex
				<< ";amount:" << Account::_amount
				<< ";closed" << std::endl;
};

int Account::getNbAccounts(void) {
	return Account::_nbAccounts;
};

int Account::getTotalAmount(void) {
	return Account::_totalAmount;
}

int Account::getNbDeposits(void) {
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts()
	<< ";total:" << Account::getTotalAmount()
	<< ";deposits:" << Account::getNbDeposits()
	<< ";withdrawals:" << Account::getNbWithdrawals()
	<< std::endl;
}

void Account::makeDeposit(int deposit) {
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex
			<< ";p_amount:" << Account::checkAmount()
			<< ";deposit:" << deposit;
	Account::_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	Account::_nbDeposits++;
	std::cout << ";amount:" << Account::checkAmount()
			<< ";nb_deposits:" << Account::_nbDeposits
			<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex
				<< ";p_amount:" << Account::checkAmount()
				<< ";withdrawal:";
	if (withdrawal > Account::_amount) {
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal;
	Account::_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	Account::_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	std::cout << ":amount:" << Account::checkAmount()
				<< ":nb_withdrawals:" << Account::_nbWithdrawals
				<< std::endl;
    return (true);
}

int Account::checkAmount(void) const {
	return Account::_amount;
}

void Account::displayStatus(void) const {
	Account::_displayTimestamp();
	std::cout << "index:"<<Account::_accountIndex
			<< ";amount:" << Account::_amount
			<< ";deposits:"<< Account::_nbDeposits
			<< ";withdrawals:" << Account::_nbWithdrawals 
			<< std::endl;
}

void Account::_displayTimestamp(void) {
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	std::cout << std::setfill('0') << "[" << std::setw(4) << (now->tm_year + 1900)
	<< std::setw(2) << now->tm_mon << std::setw(2) << now->tm_mday
	<< "_" << std::setw(2) << now->tm_hour << std::setw(2) << now->tm_min
	<< std::setw(2) << now->tm_sec << "] ";
}

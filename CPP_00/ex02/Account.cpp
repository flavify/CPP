/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 23:27:34 by fvoicu            #+#    #+#             */
/*   Updated: 2024/04/24 00:36:18 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts ;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;


Account::Account (int initial_deposit) : _amount(initial_deposit) {
  _amount = initial_deposit;
  _accountIndex = _nbAccounts;
  _nbAccounts++;
  _totalAmount += initial_deposit;
  _displayTimestamp();
  std::cout << " index:" << _accountIndex << ";";
  std::cout << "amount:" << _amount<< ";";
  std::cout << "created" << std::endl;
  
};

Account::~Account () {
  _displayTimestamp();
  std::cout << " index:" << _accountIndex << ";";
  std::cout << "amount:" << _amount<< ";";
  std::cout << "closed" << std::endl;
};

int Account::getNbAccounts (void) {
  return _nbAccounts;
}

int Account::getTotalAmount (void) {
  return _totalAmount;
}

int Account::getNbDeposits (void) {
  return _totalNbDeposits;
}

int Account::getNbWithdrawals (void) {
  return _totalNbWithdrawals;
}

void Account::displayAccountsInfos (void) {
  _displayTimestamp();
  std::cout << " accounts:" << _nbAccounts << ";";
  std::cout << "total:" << _totalAmount << ";";
  std::cout << "deposits:" << _totalNbDeposits << ";";
  std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit (int deposit) {
  _displayTimestamp();
  std::cout << " index:" << _accountIndex << ";";
  std::cout << "p_amount:" << _amount << ";";
  std::cout << "deposit:" << deposit << ";";
  _amount += deposit;
  _totalAmount += deposit;
  _totalNbDeposits++;
  _nbDeposits++;
  std::cout << "amount:" << _amount << ";";
  std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal (int withdrawal) {
  _displayTimestamp();
  std::cout << " index:" << _accountIndex << ";";
  std::cout << "p_amount:" << _amount << ";";
  std::cout << "withdrawal:";
  if (_amount < withdrawal) {
    std::cout << "refused" << std::endl;
    return false;
  }
  _amount -= withdrawal;
  _totalAmount -= withdrawal;
  _totalNbWithdrawals++;
  _nbWithdrawals++;
  std::cout << withdrawal << ";";
  std::cout << "amount:" << _amount << ";";
  std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
  return true;
}

int Account::checkAmount (void) const {
  return _amount;
}

void Account::displayStatus (void) const {
  _displayTimestamp();
  std::cout << " index:" << _accountIndex << ";";
  std::cout << "amount:" << _amount << ";";
  std::cout << "deposits:" << _nbDeposits << ";";
  std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp (void) {
  const std::time_t now = time(0);
  std::tm *ltm = std::localtime(&now);
  std::cout << "[" << 1900 + ltm->tm_year << 1 + ltm->tm_mon << ltm->tm_mday << "_";
  std::cout << ltm->tm_hour << ltm->tm_min << ltm->tm_sec << "]";
}

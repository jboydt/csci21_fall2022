#include "bank_account.h"

BankAccount::BankAccount() {

}

BankAccount::BankAccount(unsigned int accountNumber) {

}

BankAccount::BankAccount(double balance, unsigned int accountNumber) {

}

void BankAccount::deposit(double amount) {

}

bool BankAccount::withdraw(double amount) {

}

double BankAccount::getBalance() {

}

unsigned int BankAccount::getAccountNumber() {

}

string BankAccount::toString() {
  ostringstream out;

  return out.str();
}

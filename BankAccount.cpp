#include <iostream>
#include "BankAccount.h"
using namespace std;
const double baseAccount::baseIntrsRate = 0.01; // base interest rat
int baseAccount::numOfAccount = 0;
int savingAccount::numOfAccount = 0;
int checkingAccount::numOfAccount = 0;
// default ClientData constructor

baseAccount::baseAccount(int a, string b, string c, string d, int e)
{
     accountNumber = a;
     lastName = b;
     firstName = c;
     cityName = d;
     balance = e;
}

// accessor functions for accountNumber
void baseAccount::setAccountNumber(int a)
{
     accountNumber = a;
}
int baseAccount::getAccountNumber() const
{
     return accountNumber;
}

// accessor functions for lastName
void baseAccount::setLastName(string a)
{
     lastName = a;
}
string baseAccount::getLastName() const
{
     return lastName;
}

// accessor functions for firstName
void baseAccount::setFirstName(string a)
{
     firstName = a;
}
string baseAccount::getFirstName() const
{
     return firstName;
}

void baseAccount::setCityName(string a)
{
     cityName = a;
}
string baseAccount::getCityName() const
{
     return cityName;
}
// accessor functions for balance
void baseAccount::setBalance(int a)
{
     balance = a;
}
int baseAccount::getBalance() const
{
     return balance;
}
void baseAccount::incNumOfAccount() //s
{
     numOfAccount++;
}
int baseAccount::getNumOfAccount() //s
{
     return numOfAccount;
}
void baseAccount::printAccount() const //v
{
     cout << accountNumber << "    " << lastName << " " << firstName << " " << cityName << " " << balance << endl;
}
savingAccount::savingAccount(int a, string b, string c, string d, int e, double f)
{
     accountNumber = a;
     lastName = b;
     firstName = c;
     cityName = d;
     balance = e;
     floatingIntrsRate = f;
}
void savingAccount::setFloatingIntrsRate(double a)
{
     floatingIntrsRate = a;
}
double savingAccount::getFloatingIntrsRate() const
{
     return floatingIntrsRate;
}
void savingAccount::printAccount() const
{
     cout << accountNumber << "    " << lastName << " " << firstName << " " << cityName << " " << balance << " " << floatingIntrsRate << endl;
}
int savingAccount::calculateIntrs()
{
     int interest;
     interest = 10000 * baseIntrsRate + (balance - 10000) * (baseIntrsRate + floatingIntrsRate);
     return interest;
}
void savingAccount::incNumOfAccount()
{
     numOfAccount++;
}
int savingAccount::getNumOfAccount()
{
     return numOfAccount;
}
checkingAccount::checkingAccount(int a, string b, string c, string d, int e)
{
     accountNumber = a;
     lastName = b;
     firstName = c;
     cityName = d;
     balance = e;
}
void checkingAccount::printAccount() const
{
     cout << accountNumber << "    " << lastName << " " << firstName << " " << cityName << " " << balance << endl;
}
int checkingAccount::calculateIntrs()
{
      int interest;
     interest = 10000 * baseIntrsRate;
     return interest;
}
void checkingAccount::incNumOfAccount()
{
     numOfAccount++;
}
int checkingAccount::getNumOfAccount()
{
     return numOfAccount;
}
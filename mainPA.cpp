// Fig. 17.7: Fig17_7.cpp
// This program reads a random-access file sequentially, updates
// data previously written to the file, creates data to be placed
// in the file, and deletes data previously stored in the file.
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib> // exit function prototype
#include "BankAccount.cpp" // baseAccount class definition

using namespace std;
void printSavingAccounts(vector<baseAccount *> &);
void printCheckingAccounts(vector<baseAccount *> &);
//void calculateInterest(vector<baseAccount *> &); 
void readFile(ifstream &, vector<baseAccount *> &);

int main()
{
   // open file for reading and writing
   ifstream inCredit("inputFilePA.dat", ios::in);
   vector <baseAccount *> acctArray;
   string lastName;

   if ( !inCredit )
   {
      cerr << "File could not be opened." << endl;
      exit ( 1 );
   } // end if
   readFile(inCredit, acctArray);
   inCredit.close();
    cout << "\n*** Saving Accounts ***"<< endl;
    cout << left << setw(10) << "Acct #" << setw( 16 ) << "Last Name" << setw( 11 ) << "First Name" << setw( 18 ) << "City Name"
      << right << setw( 10 )  << "Balance" << setw(15) << "Floating Rate" << endl << endl;
    printSavingAccounts(acctArray);
    cout << "\n*** Checking Accounts ***" << endl;
    cout << left << setw(10) << "Acct #" << setw( 16 ) << "Last Name" << setw( 11 ) << "First Name" << setw( 18 ) << "City Name"
      << right << setw( 10 )  << "Balance" <<  endl << endl;
    printCheckingAccounts(acctArray);
    /*
    calculateInterest(acctArray);
    cout << "\n*** Saving Accounts After Calculating Interest ***"<< endl;
    cout << "    Base interest rate: " <<  setw( 10 )  << setprecision( 3) <<baseAccount::baseIntrsRate << endl;
    cout << left << setw(10) << "Acct #" << setw( 16 ) << "Last Name" << setw( 11 ) << "First Name" << setw( 18 ) << "City Name"
      << right << setw( 10 )  << "Balance" << setw(15) << "Floating Rate" << endl << endl;
    printSavingAccounts(acctArray);
    cout << "\n*** Checking Accounts After Calculating Interest ***" << endl;
    cout << left << setw(10) << "Acct #" << setw( 16 ) << "Last Name" << setw( 11 ) << "First Name" << setw( 18 ) << "City Name"
      << right << setw( 10 )  << "Balance" <<  endl << endl;
    printCheckingAccounts(acctArray);
 */
    return 0;
} // end main
void readFile(ifstream &infile, vector<baseAccount *> &base)
{
  int a;
  string l;
  string f;
  string c;
  int b;
  char m;
  double fl;
  while( !infile.eof() )
  {
    infile >> a >> l >> f >> c >> b >> m;
    if ( m == 'S' )
    {
      infile >> fl;
      savingAccount *saving = new savingAccount(a,l,f,c,b,fl);
      base.push_back(saving);
    }
    if ( m == 'C' )
    {
      checkingAccount *checking = new checkingAccount(a,l,f,c,b);
      base.push_back(checking);
    }
    
  }
}
void printSavingAccounts(vector<baseAccount *> &base)
{
 for ( int i = 0; i < base.size(); i++ )
  { 
    savingAccount *sAcntPtr = dynamic_cast<savingAccount*>(base[i]);
    cout <<sAcntPtr;
    //sAcntPtr->printAccount();
  } 
  
}
void printCheckingAccounts(vector<baseAccount *> &a)
{
 for ( int i = 0; i < a.size(); i++ )
  { 
    checkingAccount *cAcntPtr = dynamic_cast<checkingAccount*>(a[i]);
    a[i]->printAccount();
  } 
}
/* void calculateInterest(vector<baseAccount *> &a)
{
    interest = 10000 * baseIntrsRate + (balance - 10000) * (baseIntrsRate + floatingIntrsRate);
}  */

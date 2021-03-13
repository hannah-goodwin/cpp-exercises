// Hannah Goodwin
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// HW #6 - Exercise 9.20 on p 443
// 3/4/2021
// This program runs through a pre-set program to test the SavingsAccount class. At the end, the user has a chance to test with their own values, along with seeing the value in saving, even without depositing further, so long as the starting balance is high enough

#include <iostream>
#include <iomanip>
#include "SavingsAccount.hpp"

using std::cout;
using std::cin;
using std::setw;

int main () {
    // welcome banner to the user
    cout << "Welcome! Today we are going through a program that simulates a savings account for two new members starting on 1/1/2021: saver1 and saver2\n";
    
    // create the objects
    cout << "Hello saver1";
    cout << "\n";
    SavingsAccount saver1 = SavingsAccount();
    
    cout << "Hello saver2";
    cout << "\n";
    SavingsAccount saver2 = SavingsAccount();
    
    // instantiate two different objects of the class, saver1 and saver2 with balances of $2000.00 and $3000.00
    saver1.setBalance(2000);
    saver2.setBalance(3000);
    
    // the annualInterestRate is 3% as a default for all savers
    
    // print out starting balances - Jan 1, 2021
    cout << "Jan 1, 2021 balances\n";
    cout << setw(15) << "saver1: $" << saver1.getBalance() << "\n";
    cout << setw(15) << "saver2: $" << saver2.getBalance() << "\n";
    
    // calculate interest
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();
    
    // print out end of month balances - Jan 31, 2021
    cout << "Jan 31, 2021 balances\n";
    cout << "interest rate: " << saver1.getRate() << "%\n";
    cout << setw(15) << "saver1: $" << saver1.getBalance() << "\n";
    cout << setw(15) << "saver2: $" << saver2.getBalance() << "\n";
    
    // set the annualInterestRate to 4%
    cout << "!!!!\n";
    cout << "Congress just passed a new bill! Interest rates on savings accounts have gone up!\n";
    cout << "!!!!\n";
    // interest rate on savings account goes up. only need to modify on one object because the value is static
    saver1.modifyInterestRate(4); // set it to be 4%
    
    // calculate interest
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();
    
    // print out end of month balances - Feb 28, 2021
    cout << "Feb 28, 2021 balances\n";
    cout << "interest rate: " << saver1.getRate() << "%\n";
    cout << setw(15) << "saver1: $" << saver1.getBalance() << "\n";
    cout << setw(15) << "saver2: $" << saver2.getBalance() << "\n";
    
    
    // prompt the user to create their own account and set the interest rate
    cout << "Now it's your turn!\n";
    // create new account
    SavingsAccount user = SavingsAccount();
    
    // prompt for beginning balance
    cout << "How much is currently in the savings account? $";
    double userBal;
    cin >> userBal;
    // error checking on input
    while (cin.fail()) { // while the fail flag is up, happens upon bad input
        cin.clear(); // clear the buffer
        cin.ignore(100, '\n'); // ignore the first 100 characters, up to the newline character
        cout << "enter a double i.e. \"0.00\" please: ";
        cin >> userBal;
    }
    // set the user balance
    user.setBalance(userBal);
    
    // prompt for the interest rate
    cout << "What interest rate are you interested in seeing? ";
    double rate;
    cin >> rate;
    // error checking on input
    while (cin.fail()) { // while the fail flag is up, happens upon bad input
        cin.clear(); // clear the buffer
        cin.ignore(100, '\n'); // ignore the first 100 characters, up to the newline character
        cout << "enter an integer please: ";
        cin >> rate;
    }
    // modify the rate
    user.modifyInterestRate(rate);
    
    cout << "Take a look at the progress you can make with one year of saving!\n";
    cout << "Not including any additional deposits you might make in the future!\n";
    // show the progress over 12 months
    for (int month = 1; month <= 12; month++) {
        user.calculateMonthlyInterest(); // calculate that month's interest
        // print out that month's balance
        cout << "\tmonth " << month << ": $" << user.getBalance() << "\n";
    }
    
    // end the program
    cout << "Thanks for considering banking with GDWN National\n\n";

} // end of program

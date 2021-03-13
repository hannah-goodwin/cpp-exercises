// Hannah Goodwin
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// HW #6 - Exercise 9.20 on p 443
// 3/4/2021
// This program is the implementation of the SavingsAccount class. The static data member is initialized at the global scope as its value exists whether an object is instantiated/constructed or not. Each of the functions defined below have a specific purpose in seeing the interest rate manipulate the starting balances of the class objects.

#include "SavingsAccount.hpp"
#include <iostream>

using std::cout;

// static data member: annualInterestRate
double SavingsAccount::annualInterestRate = 0.0;

// PUBLIC
// constructor function, sets the private data member to zero
SavingsAccount::SavingsAccount () {
    cout << "\tYour account with GDWN National has been created!\n";
    cout << "\tWelcome to the super saver family!\n";
    savingsBalance = 0.0; // the starting balance for all accounts is $0.00
    annualInterestRate = 3.0; // the rate starts at 3%
}

// static function to update the current rate
void SavingsAccount::modifyInterestRate(double newRate) {
    // validate the data sent in to allow for program changes that might allow the user to set the value
    if (newRate < 0.0 || newRate > 100.0) { // needs to be 0 < newRate < 100
        // set to a default value of 6%
        annualInterestRate = 6.0;
        return; // returning here if needed to use the default value so that it does not re-set the value below
    }
    // set the annualInterestRate equal to newRate
    annualInterestRate = newRate;
}

// function to set the balance on the account, need to validate the data coming in
// this function is called in main when the classes are created and will be alled again whenever calculateMonthlyInterest is called
void SavingsAccount::setBalance(double balance) {
    // validate the value sent in for prep of the program getting user input
    if (balance < 0) {
        cout << "Balance cannot be negative. It has been set to $1000\n";
        savingsBalance = 1000.00; // default value of $1,000
    }
    // set sent in value to be the new balance
    savingsBalance = balance;
}

// function to calculate the monthly interest accrued and add it to the total balance
void SavingsAccount::calculateMonthlyInterest() {
    // multiply the savingsBalance by annualInterestRate divided by 12
    // divide the rate by 100 to get a percentage, not the double
    double interest = ((annualInterestRate / 100) * savingsBalance) / 12;
    
    // add the interest to the current balance
    savingsBalance+= interest;
}
// function lets the user in main see the current balance of the account
double SavingsAccount::getBalance() const { // const to protect the private data member
    return savingsBalance;
}

// function to see what the annual interest rate is
double SavingsAccount::getRate() const { // const to protect the interest rate value
    return annualInterestRate;
}

///**
// Hannah Goodwin
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// HW #2 - Exercise 4.14 p150-151
// 2/4/2021
// This program allows a user to check the status of their account at Goodwin's Department Store. The user sets the account number, current balance, all charges and credits, limit, and they can see if their account has exceeded their credit limit. There are validity checks to ensure the user doesn't put negative values into the account object.
// */
//
//#include "CreditLimits.hpp" // inclduing the interface of CreditLimits to have access to the prototypes of the class
//
//CreditLimits::CreditLimits(int num) : account(num) {
//    // user input from main() dictates the account number
//    // default values for the other variables, until the user sets those values in main with each get function
//    balance = {0.0};
//        // holds starting balance
//    newBal = {0.0};
//        // holds new balance after the calculateNewBalance function is called
//    charges = {0.0};
//        // holds the $ amount of items charged
//    credits = {0.0};
//        // holds the $ amount of credits paid
//    limit = {0.0};
//        // holds the $ amount of the max credit allowed
//}
//// setters
//void CreditLimits::setBalance(double bal) { // set the balance! but needs to verify first
//    if (bal < 0) {// need to verify all of the entered amounts to be nonnegative
//        std::cout << "Oops. Invalid starting balance. Setting to preset $100" << std::endl;
//        balance = 100.0; // chose an arbitrary amount to generate good output
//    } else {
//        balance = bal;
//    }
//}
//void CreditLimits::setCharges(double items) { // set the charges! but needs to verify first
//    if (items < 0) {// need to verify all of the entered amounts to be nonnegative
//        std::cout << "Oops. Invalid charge amount. Setting to preset $50" << std::endl;
//        charges = 50.0; // chose an arbitrary amount to generate good output
//    } else {
//        charges = items;
//    }
//}
//void CreditLimits::setCredits(double paid) { // set the amount paid! but needs to verify first
//    if (paid < 0) {// need to verify all of the entered amounts to be nonnegative
//        std::cout << "Oops. Invalid credits paid amount. Setting to preset $25" << std::endl;
//        credits = 25.0; // chose an arbitrary amount to generate good output
//    } else {
//        credits = paid;
//    }
//}
//void CreditLimits::setLimit(double max) { // set the limit! but needs to verify first
//    if (max < 0) {// need to verify all of the entered amounts to be nonnegative
//        std::cout << "Oops. Invalid limit amount. Setting to preset $250" << std::endl;
//        limit = 250.0; // chose an arbitrary amount to generate good output
//    } else {
//        limit = max;
//    }
//}
//// getters
//int CreditLimits::getAccount() const {
//    // use this get to access the account number, the first number input by the user
//    return account;
//}
//double CreditLimits::getBalance() const {
//    // this function sends the new balance to the user. If the starting balance + charges + credits is negative, the function sets it to $0
//    if (newBal < 0) {
//        return 0.0;
//    } else {
//        return newBal; // returns the new balance
//    }
//}
//double CreditLimits::getLimit() const {
//    // returns the limit set on the account
//    return limit;
//}
//// calcuate the new balance
//void CreditLimits::calculateNewBalance() {
//    // this function holds the equation to compute for the new balance of the account. This function is called in main before outputting the final results to the user
//    newBal = balance + charges - credits;
//}
//// comparison function
//bool CreditLimits::overLimit() {
//    // when this function returns true, the user will see the statement saying that the account is over the limit
//    if (newBal > limit) {
//        // new balance higher than limit
//        return true;
//    } else {
//        return false; // hopefully, the users will get this function to return false!
//    }
//}

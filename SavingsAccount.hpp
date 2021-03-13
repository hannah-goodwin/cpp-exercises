// Hannah Goodwin
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// HW #6 - Exercise 9.20 on p 443
// 3/4/2021
// This program is the interface of the SavingsAccount class. The two private data members are the savingsBalance, specific to each instance of the class, and the annualInterestRate, which has a value that changes regardless of which class instance modifies it using the public function, modifyInterestRate. The other public functions exist to help a user see the effects of the interest rate on their starting balance.

#ifndef SavingsAccount_hpp
#define SavingsAccount_hpp

class SavingsAccount {
private:
    double savingsBalance; // the amount currently in the account
    // static data member
    static double annualInterestRate; // stores the annual interest rate
public:
    SavingsAccount(); // constructor
    static void modifyInterestRate(double); // sets the new interest rate
    void setBalance(double); // sets the value of the private data member savingsBalance
    void calculateMonthlyInterest(); // calculates the monthly interest by multiplying the savingsBalance by annualInterestRate divided by 12
    double getBalance() const; // this function sends back the current balance in the account. It is constant because it should not alter the value
    double getRate() const; // this function sends back the current interest rate % . It is constant because it should not alter the value
};

#endif /* SavingsAccount_hpp */

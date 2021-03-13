///**
// Hannah Goodwin
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// HW #2 - Exercise 4.14 p150-151
// 2/4/2021
// This program allows a user to check the status of their account at Goodwin's Department Store. The user sets the account number, current balance, all charges and credits, limit, and they can see if their account has exceeded their credit limit.
// */
//
//#ifndef CreditLimits_hpp // if the interface is not already defined,
//#define CreditLimits_hpp // define it
///
//class CreditLimits {
//private:
//    int account; // account number, the first input from the user, set in the constructor
//    double balance; // beginning balance, input from user
//    double newBal; // new balance, set by the calculateNewBalance function
//    double charges; // charges to the account, input from user
//    double credits; // credits to the account, input from user
//    double limit; // maximum limit of the account, input from user
//public:
//    // constructor, only takes in the account number from the user
//    CreditLimits(int);
//    // setters
//    void setBalance(double); // parameter: balance
//    void setCharges(double); // parameter: charges
//    void setCredits(double); // parameter: credits
//    void setLimit(double); // parameter: limit
//    // getters
//    int getAccount() const; // the const is here to tell the compiler my intention not to change the variable in this function
//    double getBalance() const; // the const is here to tell the compiler my intention not to change the variable in this function
//    double getLimit() const; // the const is here to tell the compiler my intention not to change the variable in this function
//    // calculate new balance function
//    void calculateNewBalance();
//    // comparison function; check to see if the new balance is over or under
//    bool overLimit();
//};
//
//#endif /* CreditLimits_hpp */

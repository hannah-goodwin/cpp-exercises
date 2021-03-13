///**
// Hannah Goodwin
// CIS 554-M401 Object Oriented Programming in C++
// Syracuse University
// HW #2 - Exercise 4.14 p150-151
// 2/4/2021
//This program allows a user to check the status of their account at Goodwin's Department Store. The user sets the account number, current balance, all charges and credits, limit, and they can see if their account has exceeded their credit limit. The user can quit using the sentinel value of -1.
// */
//#include <iostream>
//#include "CreditLimits.hpp"
//using std::cout;
//using std::cin;
//
//int main() {
//    // sentinel variable has starting value that does not terminate the loop
//    int userInput{0};
//    
//    // while the user has not entered the sentinel value, create a new Credit account
//    cout << "Welcome to Goodwin's. Here to check on your balance?\n";
//    cout << "Please enter the account number (or -1 to quit): ";
//    cin >> userInput; // accepting input
//    
//    // start the while loop
//    while (userInput != -1) {
//        // create the new credit account object here using the input as the account number
//        CreditLimits account = CreditLimits(userInput);
//        
//        // accept input for balance at the beginning of the month, total $ of items charged this month, total $ credits to the account this month, and the credit limit
//        cout << "Enter beginning balance: $";
//        double bal; // create new variable to pass through the stated balance
//        cin >> bal;
//        account.setBalance(bal); // set the balance in the object
//        cout << "Enter total charges: $";
//        double items; // create new variable to pass through the stated items charged
//        cin >> items;
//        account.setCharges(items); // set the $ amount of charges in the object
//        cout << "Enter total credits: $";
//        double paid; // create new variable to pass through the stated credits
//        cin >> paid;
//        account.setCredits(paid); // set the $ amount of credits paid
//        cout << "Enter credit limit: $";
//        double max; // new variable for the maximum amount allowed on the account
//        cin >> max;
//        account.setLimit(max); // set the $ amount of the credit limit
//        
//        // output the account number, credit limit, and new balance
//        account.calculateNewBalance();
//        // calling the get functions here to output the values
//        cout << "New balance is $" << account.getBalance() << "\n";
//        cout << "Account         " << account.getAccount() << "\n";
//        cout << "Credit Limit   $" << account.getLimit()   << "\n";
//        cout << "Balance        $" << account.getBalance() << "\n";
//        
//        // check to see if over the limit
//        if (account.overLimit()) {
//            cout << "Credit Limit Exceeded. \n\n";
//        } else {
//            cout << "\n"; // just for the sake of aesthetically pleasing output
//        }
//        
//        // using this to ensure that the buffer is cleared
//        cin.sync();
//        
//        //  check to see if user wants to quit by asking for input again
//        cout << "Welcome to Goodwin's. Here to check on your balance?\n";
//        cout << "Please enter the account number (or -1 to quit): ";
//        cin >> userInput; // accepting input
//    }
//    // end of program
//}

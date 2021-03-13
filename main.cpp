/**
 Hannah Goodwin
 CIS 554-M401 Object Oriented Programming in C++
 Syracuse University
 HW #4 - Exercises 6.57 - 6.61 p 281-282
 2/18/2021
This program can be used to test the class ProblemSet. A user can input the type of arithmetic problems and what level they want to go through. There are 5 different types and 4 levels. Once the user has entered 10 questions, the user is told whether they passed with a score of 75% or above, or if they need some extra help from the teacher.
 */
#include <iostream>
#include <iomanip>
// include the class interface
#include "ProblemSet.hpp"

using std::cout;
using std::cin;

int main () {
    // Welcome banner to the user, see if they want to play
    cout << "WELCOME!\n";
    cout << "What's your favorite number? (-1 to quit): ";
    int input{0};
    cin >> input; // the user can input -1 to leave the program
    if (input == -1) {
        return 0;
    }
    if (input == 42) { // easter egg
        cout << "nerd :P\n";
    }
    // using this to clear the buffer, just in case
    cin.clear();
    
    // start telling the student the rules here
    cout << "So good to see you.\n"
         << "Here's the type of questions you can answer:\n";
    cout << "1: addition\n2: subtraction\n3: multiplication\n4: division\n5: combination of all\n";
    
    // prompt user for arithmetic type: 1 - addition, 2 - subtraction, 3 - multiplication, 4 - division, 5 - random mixture of all
    cout << "What type of arithmetic do you want to work on? ";
    int type{0}; // creation of the type variable
    cin >> type;
    cout << "Here's the levels to choose from:\n";
    cout << "1: single digit\n2: double digit\n3: triple digit\n4: quadruple digit\n";
    
    // prompt user for difficulty level: 1 - single digit, 2 - double digit, etc
    cout << "What level do you want to attempt? ";
    int level{0}; // creation of the type variable
    cin >> level;
    cout << "Great! Let's get started.\n";
    
    // ProblemSet object takes in the arithmetic type and the difficulty level
    ProblemSet problems = ProblemSet(type, level);
    // calling the questions function to ask the student questions according to all preferences
    problems.questions();
    
    // see if the student passed the level, score >= 75%
    cout << "You've reached the end of the problem set. Let's see how you did.\n";
    
    // call the function to check if the student passed, save it to a new variable to give two responses depending on the condition
    bool passed = problems.studentPassed();
    
    // adding this output to simulate the calculation of the grade
    cout << " . . . . . . . . . . . .\n";
    cout << " . . . calculating . . .\n";
    cout << " . . . . . . . . . . . .\n";
    if (passed == true) { // they passed! output congratulatory statement
        cout << "Congratulations! You achieved a score of 75% or higher!\n\n\n";
    } else { // they didn't pass and need some extra help from in-person teaching
        cout << "Please ask your teacher for extra help.\n\n\n";
    }
    
    // restart the program for another student
    main();
    
} // end of program

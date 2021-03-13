/**
 Hannah Goodwin
 CIS 554-M401 Object Oriented Programming in C++
 Syracuse University
 HW #4 - Exercises 6.57 - 6.61 p 281-282
 2/18/2021
 This program is the implementation of the ProblemSet class. The private functions are interconnected. The correctAnswer requires an argrument to be passed as it is called by the four arithmetic functions. The digits function is also called by the arithmetic functions but uses the difficulty private data member to do it's calculation. The response functions print output to the student user according to a random number generated each time it is called.
 */

#include "ProblemSet.hpp"
#include <cstdlib> // including to use rand() function
#include <iomanip> // including to set up output nicely
#include <iostream>

using std::cout;
using std::cin;

// PRIVATE FUNCTIONS
// correctResponse returns a random response each time the student enters a correct answer AND increments the private data member: correct
void ProblemSet::correctResponse(){
    correct += 1; // increment the count of number of questions answered correctly by 1
    int random = rand() % 5 + 1;
    switch (random) {
        case 1:
            cout << "Correct!\n";
            break;
        case 2:
            cout << "That's right!\n";
            break;
        case 3:
            cout << "Nice! Great job.\n";
            break;
        case 4:
            cout << "Whoa! That's perfect!\n";
            break;
        case 5:
            cout << "Fantastic!\n";
            break;
        default:
            break;
    }
}

// incorrectResponse returns a random response each time the student enters an incorrect answer
void ProblemSet::incorrectResponse(){
    int random = rand() % 5 + 1;
    switch (random) {
        case 1:
            cout << "Incorrect. Keep trying.\n";
            break;
        case 2:
            cout << "Almost, but not quite. Try again.\n";
            break;
        case 3:
            cout << "Oh no! That's not right. Give it one more go.\n";
            break;
        case 4:
            cout << "Don't worry, you're close to the answer. Try again.\n";
            break;
        case 5:
            cout << "Not quite, please try once more.\n";
            break;
        default:
            break;
    }
}

// this function takes all the code that could be copied in all the arithmetic functions and puts it all in once place
void ProblemSet::correctAnswer(int answer){
    // ask user for the correct answer
    int userAns;
    cin >> userAns;
    // if correct, correctResponse() and return;
    if (userAns == answer) {
        correctResponse();
        return;
    } else { // if not correct, give a prompt from incorrectResponse and prompt for correct answer from user again
        incorrectResponse();
        cin >> userAns;
        if (userAns == answer) {
            // if it is no correct, send a prompt from correctResponse and return control to the calling function, multiplication
            correctResponse();
            return;
        } else { // if not correct, give a prompt from the incorrectResponse function and return to the calling function, addition
            cout << "The correct answer was: " << answer << "\n";
            return;
        }
    }
}

// this function is dependent on the value of difficulty. Regardless of the arithmetic type, this function will be called twice EACH time a question is asked. It will return one operand of the correct number of digits each time it is called
int ProblemSet::digits() {
    int num{0};
    if (difficulty == 1) {
        num = rand() % 10; // want a number between 0-9
        return num;
    } else if (difficulty == 2) {
        num = rand() % 100 + 10; // want a number between 10-99
        return num;
    } else if (difficulty == 3) {
        num = rand() % 900 + 100; // want a number between 100-999
        return num;
    } else if (difficulty == 4) {
        num = rand() % 9000 + 1000; // want a number between 1000-9999
        return num;
    }
    return -1; // if this happens, it is an ERROR
}

// Each of the arithmetic functions will call digits function twice
// addition
void ProblemSet::addition(){
    int operand1 = digits();
    int operand2 = digits();
    // calculating the answer
    int answer = operand1 + operand2;
    cout << "What is " << operand1 << " plus " << operand2 << "?";
    correctAnswer(answer);
}
// subtraction
void ProblemSet::subtraction(){
    int operand1 = digits();
    int operand2 = digits();
    // calculating the answer
    int answer = operand1 - operand2;
    cout << "What is " << operand1 << " minus " << operand2 << "?";
    correctAnswer(answer);
}
// multiplication
void ProblemSet::multiplication(){
    int operand1 = digits();
    int operand2 = digits();
    // calculating the answer
    int answer = operand1 * operand2;
    cout << "What is " << operand1 << " times " << operand2 << "?";
    correctAnswer(answer);
}
// division
void ProblemSet::division(){
    int operand1 = digits();
    int operand2 = digits();
    // cannot divide by 0, set the second operand to 1 to avoid issue
    if (operand2 == 0) {
        operand2 = 1;
    }
    // calculating the answer
    int answer = operand1 / operand2;
    cout << "What is " << operand1 << " divided by " << operand2 << "?";
    // adding this instruction to be clear to the student
    cout << "answer in integer form: ";
    correctAnswer(answer);
}

// PUBLIC FUNCTIONS
// constructor
ProblemSet::ProblemSet(int arithmeticType, int difficultyLevel){
    // check validity of the type entered
    if (arithmeticType > 5 || arithmeticType < 1) {
        cout << "Oh noes! That type doesn't exist in our system yet.\n"
        << "Try addition for now\n";
        type = 1;
    } else {
        // otherwise, the user entered value is fine
        type = arithmeticType;
    }
    
    // check validity of the level entered
    if (difficultyLevel > 4 || difficultyLevel < 1) {
        cout << "Oh noes! That level doesn't exist in our system yet.\n"
        << "Try level 1 for now\n";
        difficulty = 1;
    } else {
        // otherwise, the user entered value is fine
        difficulty = difficultyLevel;
    }

    // initialize correct to 0
    correct = 0;
}

// find if the student has passed the level
bool ProblemSet::studentPassed(){
    // double to hold the calculation using the private data member divided by total number of questions asked
    double correctPercentage = correct / 10.0;
    if (correctPercentage >= 0.75) { // score needed to pass the level is 75%
        return true; // true is sent out to main function
    } else {
        return false; // false is sent out to main function
    }
}

// this function is used to ask questions of the student. It loops 10 times
void ProblemSet::questions(){
    for (int counter = 0; counter < 10; counter++) {
        // each condition matches up to the instructions given to the user in main function
        if (type == 1) {
            addition();
        } else if (type == 2) {
            subtraction();
        } else if (type == 3) {
            multiplication();
        } else if (type == 4) {
            division();
        } else if (type == 5) { // will call a different arithmetic question for each loop
            // generate a random number
            int random = rand() % 4 + 1;
            if (random == 1) {
                addition();
            } else if (random == 2) {
                 subtraction();
            } else if (random == 3) {
                 multiplication();
            } else if (random == 4) {
                 division();
            }
        } else {
            // ERROR: should never get here
            cout << "Oops! Unable to ask you the right kind of questions.\n";
        }
    }
}

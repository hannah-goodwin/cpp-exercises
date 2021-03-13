/**
 Hannah Goodwin
 CIS 554-M401 Object Oriented Programming in C++
 Syracuse University
 HW #5
 2/25/2021
This program allows a user to rate some of the best movies since 1930. The user can view the entire movie list, or one decade at a time, give their rating, and at the end, see all of the movies they rated along with a visualization of their ratings. This main function shows off the capabilities of the MovieRatings class.
 */
// needed for managing input and output
#include <iostream>
#include <iomanip>
// need to include the self-written class interface
#include "MovieRatings.hpp"
// make code less verbose
using std::cout;
using std::cin;
using std::setw;

 // TODO: pass by pointer

// MOVIE RATINGS
int main () {
    // welcome banner for the user
    cout << setw(30) << "" << "It's The ___ For Me: A Movie Rating Program by Goodwin, Inc.\n";
    cout << "\n";
    cout << "Choose the movies you want to rate, put in their ratings, and see what your ratings look like!\n";
    
    // char array to hold their name
    cout << "Rating your favorite movies is hard, so let's start with something easy.\n";
    cout << "What's your name? ";
    char userName[100]; // setting a high length so that it is prepared for almost any input
    cin.get(userName, 100); // takes the full line so that the input buffer isn't jammed later on when needing to get additional user input
    cout << "Great.\nBegin rating " << userName << "'s movies.\n";

    // create MovieRatings object
    MovieRatings myRatings = MovieRatings();
    
    // display movie choices
    cout << "Here are the movies you can rate right now:\n";
    myRatings.displayMovies();
    
    // this is the part to start the loop at
    bool wantToQuit = false; // using a boolean value to track whether the user wants to quit
    while (wantToQuit == false) {
        // choose a movie to rate
        cout << "What movie do you want to rate? Type in the movie's list number: ";
        int movieToRate{0}; // holds movie number as presented at beginning of program
        cin >> movieToRate; // pass in this variable to the rateMovie function
        
        // error checking on input
        while (cin.fail()) { // while the fail flag is up, happens upon bad input
            cin.clear(); // clear the buffer
            cin.ignore(100, '\n'); // ignore the first 100 characters, up to the newline character
            cout << "enter an integer please: ";
            cin >> movieToRate;
        }
        
        // give the rating of the movie
        cout << "How many stars do you give it? Out of 5, must be a whole number: ";
        int stars{0}; // holds rating
        cin >> stars;
        
        // error checking on input
        while (cin.fail()) { // while the fail flag is up, happens upon bad input
            cin.clear(); // clear the buffer
            cin.ignore(100, '\n'); // ignore the first 100 characters, up to the newline character
            cout << "enter an integer please: ";
            cin >> stars;
        }
        
        // call the function to rate the movie
        myRatings.rateMovie(movieToRate, stars);
        
        // this is where to ask the user if they have another movie to rate
        cout << "\nWant to rate another movie? (y/n): ";
        char answer; // holds the user's answer to this question
        cin >> answer;
        
        // check what the user chose
        if (answer == 'n' || answer == 'N') {
            wantToQuit = true;
            break; // end the while loop and jump to displaying the ratings
        }
        cout << "\n"; // placing this here for output aesthetics
        
        // ask the user if they want to be reminded of movie list
        cout << "Do you want to see the entire movie list again? (y/n): ";
        char answer2; // holds the user's answer to this question
        cin >> answer2;
        // check what the user chose
        if (answer2 == 'y' || answer2 == 'Y') {
            // if yes, display the full list
            myRatings.displayMovies();
        }
        cout << "\n"; // placing this here for output aesthetics
        
        // ask the user if they want to see a specific decade
        cout << "Do you want to see a specific decade? (y/n): ";
        char answer3; // holds the user's answer to this question
        cin >> answer3;
        if (answer3 == 'y' || answer3 == 'Y') {
            // if yes, have to ask for the decade
            cout << "1: 1930's, 2: 1940's, 3: 1950's, 4: 1960's, 5: 1970's, 6: 1980's, 7: 1990's, 8: 2000's, 9: 2010's, or 10: 2020\n";
            cout << "Enter the decade: ";
            int choice{0}; // holds the user's decade choice
            cin >> choice;
            // error checking on input
            while (cin.fail()) { // while the fail flag is up, happens upon bad input
                cin.clear(); // clear the buffer
                cin.ignore(100, '\n'); // ignore the first 100 characters, up to the newline character
                cout << "enter an integer please: ";
                cin >> choice;
            }
            // validate choice to make sure not to pass bad data to the function
            if (choice < 1 || choice > 10) {
                cout << "Bad input :( Let's look at the 1970's\n";
                choice = 5;
            }
            // then call the function and pass the choice by reference
            myRatings.displayDecade(choice);
        }
        cout << "\n"; // placing this here for output aesthetics
    }
    
    // display the ratings with stars that the user rated
    cout << "\n"; // placing this here for output aesthetics
    cout << setw(15) << userName << "'s ratings";
    cout << "\n\n"; // placing this here for output aesthetics
    
    // calling the function to display
    myRatings.displayRatings();
    cout << "\n";
    
} // end of program

////Hannah Goodwin
////CIS 554-M401 Object Oriented Programming in C++
////Syracuse University
////HW #3 - Exercise 5.16 p206
////2/11/21
///*
// This program asks the user to input 5 values to display to the console as bar graphs. A star (*) represents each number. The user is allowed to enter any numbers. The program ends when the user enters a 'q' or 'Q' character.
// */
//
//#include <iostream>
//#include <string>
//#include "Graph.hpp"
//using std::cin;
//using std::cout;
//using std::endl;
//
//int main () {
//    // welcome banner to the user
//    cout << "Hello!\n";
//    cout << "Enter any character to begin (q to quit): ";
//    char exitChar; // sentinel value for the user to exit the program
//    cin >> exitChar; //
//    if (exitChar == 'q' || exitChar == 'Q') {
//        return 0; // ending the program prematurely upon user's elected exit
//    }
//    // create a new Graph object
//    Graph chart = Graph();
//    // creating an array of integers to collect the user-set values
//    int data [5];
//    
//    // for loop to take user input 5 times
//    for (int i = 1; i <= 5; i++) {
//        // values of i will be 1, 2, 3, 4, and finally 5 before the loop terminates
//        
//        // clear the buffer from the input
//        cin.clear();
//        
//        // use the array structure to collect the input
//        cout << "enter an integer value: "; // prompt user for input
//        int input; // new variable to hold the user-picked number of stars for the graph
//        cin >> input;
//        
//        // need the i-1 to place the input into the correct index of the array, spots in data are 0, 1, 2, 3, and 4
//        data[i-1] = input;
//    }
//    // set all the values in the object
//    int a = data[0]; // first value
//    int b = data[1]; // second value
//    int c = data[2]; // third value
//    int d = data[3]; // fourth value
//    int f = data[4]; // fifth value
//    
//    // one Graph object has the information for all five bar charts
//    chart = Graph(a, b, c, d, f); // pass the values to the Graph object
//    
//    // announce the beginning of the graphs to the user
//    cout << "\ngraphs\n" << endl;
//    // calling the drawing of the graphs function
//    chart.drawGraphs();
//    cout << "\n"; // adding ending newline to make output prettier
//    
//    // calling main() to restart the program. User can decide to quit at the beginning of the next call
//    main();
//    
//} // end of program

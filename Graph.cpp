//Hannah Goodwin
//CIS 554-M401 Object Oriented Programming in C++
//Syracuse University
//HW #3 - Exercise 5.16 p206
//2/11/21
/*
 The implementation file demonstrates the HOW of the class. The default constructor is necessary because I wanted to declare the object's existence before I knew the values. The final implementation of the main function enables me to no longer due that, but I decided to keep the default constructor anyway. The second constructor contains the values sent in from the user. The constructor is technically not setting the values itself; the private function makeValid() is doing that, along with validating the input. The drawGraphs() function does the same thing 5 times: prints the bar graphs according to the specified value. 
 */

#include "Graph.hpp"
// this library and these functions are included to produce output in the drawGraphs() function
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// default constuctor
Graph::Graph() {} // have this one called to create the object without knowing the values
/*
 more complex constructor, call this one the user has entered the values
 calling the private function, makeValid, when assigning the arguments to the private data members to be sure the values are between 1 and 30
 assigning the values in the body of the constructor to make it clear
 */
Graph::Graph(int a, int b, int c, int d, int f) {
    // after being sent in, the values are made valid by the private function to ensure the output to the display is good and possible
    // the private data members are set here by the output of the makeValid() function
    graph1 = makeValid(a);
    graph2 = makeValid(b);
    graph3 = makeValid(c);
    graph4 = makeValid(d);
    graph5 = makeValid(f);
}
// this function exists to make the numbers passed through valid for the object
int Graph::makeValid(int numToTest) {
    if (numToTest <= 0) { // the number needs to be greater than 0
        return 1; // return the smallest allowable value
    } else if (numToTest > 30) { // the number needs to be smaller than or equal to 30
        return 30; // return the largest allowable value
    }
    return numToTest; // if the number sent in meets the constraints, just return that value
}
void Graph::drawGraphs() {
    /*
     Each graph begins with the "|" character, then the loop prints the number of stars that are needed for the graph, and end with a new line character
     */
    // each loop: for all the values from 0 to the graph value, print a * without spaces inbetween
    // GRAPH 1
    cout << "|";
    for (int i = 0; i < graph1; i++) {
        cout << "*";
    }
    cout << "\n"; // end with a newline
    // GRAPH 2
    cout << "|";
    for (int i = 0; i < graph2; i++) {
        cout << "*";
    }
    cout << "\n"; // end with a newline
    // GRAPH 3
    cout << "|";
    for (int i = 0; i < graph3; i++) {
        cout << "*";
    }
    cout << "\n"; // end with a newline
    // GRAPH 4
    cout << "|";
    for (int i = 0; i < graph4; i++) {
        cout << "*";
    }
    cout << "\n"; // end with a newline
    // GRAPH 5
    cout << "|";
    for (int i = 0; i < graph5; i++) {
        cout << "*";
    }
    cout << "\n"; // end with a newline
}

//Hannah Goodwin
//CIS 554-M401 Object Oriented Programming in C++
//Syracuse University
//HW #3 - Exercise 5.16 p206
//2/11/21
/*
 The interface file shows that the numbers input by the user and the function that returns valid versions of the numbers are private to the class. The public parts are the default constructor, the constructor with the private data members sent in, and the drawGraphs function. There are no getters and setters because the main function never requires the ability to get/set private data members in this case.
 */

#ifndef Graph_hpp
#define Graph_hpp

class Graph {
private:
    // the values sent in from the users
    int graph1;
    int graph2;
    int graph3;
    int graph4;
    int graph5;
    // private function to validate the user input
    int makeValid(int);
public:
    // constructors
    Graph(); // default constructor
    Graph(int, int, int, int, int); // constructor with the values set
    // no getter functions are needed because the main() never needs to get the values
    // draw graphs function
    void drawGraphs();
};

#endif /* Graph_hpp */

/**
 Hannah Goodwin
 CIS 554-M401 Object Oriented Programming in C++
 Syracuse University
 HW #4 - Exercises 6.57 - 6.61 p 281-282
 2/18/2021
This program is the interface of the ProblemSet class. From the main function, can call three public functions: the constructor, which requires user input, the questions function to answer arithmetic problems, and the studentsPassed function, which returns a bool and determines the ending message the user sees. There are 3 private data members: the preferred arithmetic type, the level of difficulty, and the amount the student user answers correctly. The private functions are interconnected. The correctAnswer requires an argrument to be passed as it is called by the four arithmetic functions. The digits function is also called by the arithmetic functions but uses the difficulty private data member to do it's calculation. The response functions print output to the student user.
 */

#ifndef ProblemSet_hpp // if not defined,
#define ProblemSet_hpp // define it

// the beginning of the class interface
class ProblemSet{
private:
    // VARIABLES
    int type; // entered by user, validated when in the constructor
    int difficulty; // entered by user, validated when in the constructor
    // variable to count the number of correct
    int correct;
    // FUNCTIONS
    // functions that print out a random response when correct / incorrect answer is given
    void correctResponse(); // this function sets the correct data member
    void incorrectResponse();
    void correctAnswer(int); // this function is called by all of the arithmetic public functions
    int digits(); // this funtion returns the number of digits according to the difficulty level
    // the arithmetic functions are called in the questions function
    void addition();
    void subtraction();
    void multiplication();
    void division();
public:
    // these are the three functions that are called in the main function
    // constructor takes in the arithmetic type and and the difficulty level
    ProblemSet(int, int);
    // function to calculate if the student achieved a score of 75% or above
    bool studentPassed();
    // question creator that can keep prompting the student
    void questions();
};


#endif /* ProblemSet_hpp */

/**
 Hannah Goodwin
 CIS 554-M401 Object Oriented Programming in C++
 Syracuse University
 HW #5
 2/25/2021
This program is the interface of the MovieRatings class. Almost all of the functions are public because the logic of the program is handled in main due to the large amount of user input that is required to keep making decisions.
 */

#ifndef MovieRatings_hpp
#define MovieRatings_hpp

class MovieRatings {
private:
    // private function to validate the user input for range
    int makeValid(int, int);
public:
    MovieRatings(); // constructor needs to take in the user's name
    void displayMovies(); // this function displays the movies to the user
    void displayDecade(int&); // this function returns just the movies from a specified decade. Pass by Reference!!
    void displayRatings(); // this function prints out the stars associated with each movie
    void rateMovie(int, int); // passing in list number of movie and the rating
//    const char** getMovieList();
    
};

#endif /* MovieRatings_hpp */


/**
 Hannah Goodwin
 CIS 554-M401 Object Oriented Programming in C++
 Syracuse University
 HW #5
 2/25/2021
This program holds the movies that a user can rate, and performs all the work listed in the interface. Movies selected from:
 - https://www.filmsite.org/200films.html
 - https://editorial.rottentomatoes.com/guide/the-best-movies-of-2020/
 */
#include <iostream>
#include <iomanip>
#include <array>
#include <vector>
#include "MovieRatings.hpp"

using std::cout;
using std::setw;
using std::vector;

// GLOBAL
/**
 Made the movies array a global because I found that this was the way that it worked. Originally, I had it declared in the interface and in the constructor, which initially worked. As time went on, the array had NULL pointers in random positions and it wouldn't run. I am interested in finding out why that happened and why the global declaration works.
*/
// array holding all the movies, will not change
// using an array of pointers to the string movie titles
const char* movies[50] = {"All Quiet On The Western Front (1930)", "Dracula (1931)", "Trouble in Paradise (1932)", "Gone With The Wind (1939)", "The Wizard of Oz (1939)", "Fantasia (1940)", "Casablanca (1942)", "Meet Me In St. Louis (1944)", "It's A Wonderful Life (1946)", "The Third Man (1949)","An American In Paris (1951)", "Singin' In The Rain (1952)", "Roman Holiday (1953)", "12 Angry Men (1957)", "Vertigo (1958)", "Psycho (1960)", "West Side Story (1961)", "Dr. Strangelove or: (1964)", "The Graduate (1967)", "2001: A Space Odyssey (1968)", "The Godfather (1972)", "Chinatown (1974)", "Taxi Driver (1976)", "Star Wars (1977)", "Apocalypse Now (1979)", "The Empire Strikes Back (1980)", "Raging Bull (1980)", "E.T. - The Extra-Terrestrial (1982)", "The Terminator (1984)", "Ferris Bueller's Day Off (1986)", "GoodFellas (1990)", "The Silence of the Lambs (1991)", "Schindler's List (1993)", "Pulp Fiction (1994)", "The Shawshank Redemption (1994)", "Lord of the Rings: The Fellowship of the Ring (2001)", "Eternal Sunshine of the Spotless Mind (2004)", "Sideways (2004)", "No Country for Old Men (2007)", "The Dark Knight (2008)", "The Social Network (2010)", "The Wolf of Wall Street (2013)", "Whiplash (2014)", "Black Panther (2018)", "Little Women (2019)", "EMMA. (2020)", "Happiest Season (2020)", "Borat: Subsequent Moviefilm (2020)", "Athlete A (2020)", "One Night in Miami (2020)"};

// vectors -- these work hand in hand in the rateMovie() and displayRatings() functions
vector<int> ratedMovies; // this vector is to hold the movies that have been rated
vector<int> ratings; // this vector is to hold the ratings of those movies

// PRIVATE
// this function will return the number to validate if that number fits within the range, otherwise it returns a default value
// the maximum parameter is to help me code for whether it is a movie in the list or a rating. Movie maximum is 50 and rating maximum is 5
int MovieRatings::makeValid(int numToTest, int maximum) {
    if (maximum == 50) { // if need to validate movie list number
        if (numToTest > maximum || numToTest < 1) {
            cout << "movie entered was not within the limits. \n";
            return 1;
        }
    } else if (maximum == 5) { // or it need to validate rating given
        if (numToTest > maximum || numToTest < 1) {
            cout << "rating entered was not within the limits. we give your performance 1 star\n";
            return 1;
        }
    }
    return numToTest;
}

// PUBLIC
// keep track of all the movies the user rates
int totalMovies{0};

// constructor
MovieRatings::MovieRatings() {}

// this function prints out to the user all the movies the user can rate
void MovieRatings::displayMovies() {
    int decades = 0; // use this to count through the decades for better-looking output
    int movieNumber = 1; // use to print out the line number, will start at 1
    // Range-based for loop
    for (const char* movie : movies) { // for all the movies in the global array movies
        // I am using a switch statement here because I thought it was easier for printing out the decade in this case
       switch (decades) { // increasing by 5 because there are 5 movies in each decade
           case 0:
               cout << "The 1930's\n";
               break;
           case 5:
               cout << "The 1940's\n";
               break;
           case 10:
               cout << "The 1950's\n";
               break;
           case 15:
               cout << "The 1960's\n";
               break;
           case 20:
               cout << "The 1970's\n";
               break;
           case 25:
               cout << "The 1980's\n";
               break;
           case 30:
               cout << "The 1990's\n";
               break;
           case 35:
               cout << "The 2000's\n";
               break;
           case 40:
               cout << "The 2010's\n";
               break;
           case 45:
               cout << "2020\n";
               break;
           default:
               break;
       }
        cout << setw(5) << movieNumber << ": " << movie << "\n"; //print out the next movie in the array
        // increment the two counting variables
        movieNumber++;
        decades++;
    }
}
// passing the user-specified decade to this function to display those 5 movies only
void MovieRatings::displayDecade(int& decadeWanted) {
    // passed the decade by reference
    int* decade = &decadeWanted;
    int start{0}; // first index of the movies array
    
    // 1: 1930's [0-4], 2: 1940's [5-9], 3: 1950's [10-14], 4: 1960's [15-19], 5: 1970's [20-24], 6: 1980's [25-29], 7: 1990's [30-34], 8: 2000's [35-39], 9: 2010's [40-44], or 10: 2020 [45-49]
    switch (*decade) { // increasing by 5 because there are 5 movies in each decade
        case 2:
            start = 5;
            break;
        case 3:
            start = 10;
            break;
        case 4:
            start = 15;
            break;
        case 5:
            start = 20;
            break;
        case 6:
            start = 25;
            break;
        case 7:
            start = 30;
            break;
        case 8:
            start = 35;
            break;
        case 9:
            start = 40;
            break;
        case 10:
            start = 45;
            break;
        default:
            // the default is the 1930's, with start = 0
            break;
    }

    for (int counter{0}; counter < 5; counter++) { // going to loop 5 times
        cout << setw(5) << start+1+counter << ": " << movies[start+counter] << "\n"; //print out the next movie
        // start+1+counter for the movie's list number
    }
    
}

// this function prints out all the movies the user rated along with the stars given
void MovieRatings::displayRatings(){
    // tell the user how many they rated
    if (totalMovies == 1) {
        cout << "You only rated " << totalMovies << " movie!\n" ;
    } else {
        cout << "You rated " << totalMovies << " movies!\n" ;
    }
    
    // for loop to go through all of the movies the user rated
    for (int movie = 0; movie < ratedMovies.size(); movie++) {
        // here, movie means the position
        
        // grab the movie number
        int movieToDisplay = ratedMovies.at(movie); // this will grab the list number of the movie
        
        // print that movie's title based on the global movies array
        cout << movies[movieToDisplay-1] << ": ";
        // need to subtract 1 to make up for the indexing
        // this will print the movie at that list number. Ex: if movieToDisplay == 42, this will print "The Wolf of Wall Street (2013): "
        
        // grab the rating from the global ratings vector
        int ratingToDisplay = ratings.at(movie);
        
        // for that number, print that many stars RIGHT next to the movie's title
        for (int stars = 0; stars < ratingToDisplay; stars++) {
            cout << "*";
        }
        
        // new line for the next film's rating
        cout << "\n";
    }
}

// this function assigns a rating to a movie
void MovieRatings::rateMovie(int movie, int rating) {
    
    // make the entered values valid AND THEN append the new values to the vectors
    ratedMovies.push_back(makeValid(movie, 50)); // add the movie's list number to the global vector
    
    ratings.push_back(makeValid(rating, 5)); // add the movie's rating to the global vector
    
    // increment global variable for keeping track of the movies the user rated
    totalMovies++;
}

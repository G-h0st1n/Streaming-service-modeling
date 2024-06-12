// Movie.h
#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <vector>

using namespace std;

class Movie {
protected:
    int id;
    string name;
    int length; // in minutes
    string genre;
    vector<int> ratings;

public:
    Movie(int id, const string &name, int length, const string &genre);
    virtual ~Movie() = default;

    void addRating(int rating);
    double getAverageRating() const;

    virtual void display() const = 0; // Pure virtual function
};

#endif // MOVIE_H

// Movie.h
#ifndef SERIES_H
#define SERIES_H

#include <string>
#include <vector>

using namespace std;

class Series {
protected:
    int id;
    string name;
    string name_of_episodes;
    int amount; //number of seasons
    int length; // in episodes
    string genre;
    vector<int> ratings;

public:
    Series(int id, const string &name, string name_of_espisodes, int amount, int length, const string &genre);
    virtual ~Series() = default;

    void addRating(int rating);
    double getAverageRating() const;

    virtual void display() const = 0; // Pure virtual function
};

#endif // SERIES_H

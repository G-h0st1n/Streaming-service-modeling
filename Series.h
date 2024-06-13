#ifndef SERIES_H
#define SERIES_H

#include "Video.h"
#include <vector>
#include <string>
#include <iostream>
#include <numeric>

using namespace std;

class Series : public Video {
    vector<string> episodes;
    int seasons;
    vector<double> ratings;

public:
    Series(int id, const string &name, int length, const string &genre,
           const vector<string> &episodes, int seasons);

    void display() const override;

    void addRating(double rating);
    double getAverageRating() const;

    const vector<string>& getEpisodes() const { return episodes; }
};

#endif // SERIES_H

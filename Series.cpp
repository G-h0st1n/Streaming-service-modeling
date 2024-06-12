// Series.cpp
#include "Series.h"
#include <numeric>
using namespace std;

Series::Series(int id, const string &name, string name_of_espisodes, int amount, int length, const string &genre)
    : id(id), name(name), name_of_episodes(name_of_episodes), amount(amount), length(length), genre(genre) {}

void Series::addRating(int rating) {
    if (rating >= 1 && rating <= 5) {
        ratings.push_back(rating);
    }
}

double Series::getAverageRating() const {
    if (ratings.empty()) return 0.0;
    double sum = accumulate(ratings.begin(), ratings.end(), 0);
    return sum / ratings.size();
}

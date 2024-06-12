//  Movie.cpp
#include "Movie.h"
#include <numeric>
using namespace std;

Movie::Movie(int id, const string &name, int length, const string &genre)
    : id(id), name(name), length(length), genre(genre) {}

void Movie::addRating(int rating) {
    if (rating >= 1 && rating <= 5) {
        ratings.push_back(rating);
    }
}

double Movie::getAverageRating() const {
    if (ratings.empty()) return 0.0;
    double sum = accumulate(ratings.begin(), ratings.end(), 0);
    return sum / ratings.size();
}

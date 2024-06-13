#include "Video.h"
#include <numeric>
using namespace std;

Video::Video(int id, const string &name, int length, const string &genre)
    : id(id), name(name), length(length), genre(genre) {}

void Video::addRating(int rating) {
    if (rating >= 1 && rating <= 5) {
        ratings.push_back(rating);
    }
}

double Video::getAverageRating() const {
    if (ratings.empty()) return 0.0;
    double sum = accumulate(ratings.begin(), ratings.end(), 0);
    return sum / ratings.size();
}

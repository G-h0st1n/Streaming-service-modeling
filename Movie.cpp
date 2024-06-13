#include "Movie.h"
#include <iostream>
#include <numeric>
using namespace std;

Movie::Movie(int id, const string &name, int length, const string &genre)
    : Video(id, name, length, genre) {}

void Movie::display() const {
    cout << "Movie: " << name << "\n";
    cout << "Genre: " << genre << "\n";
    cout << "Length: " << length << " minutes\n";
    cout << "Average Rating: " << getAverageRating() << "\n";
}

void Movie::addRating(double rating) {
    if (rating >= 1.0 && rating <= 5.0) {
        ratings.push_back(rating);
    }
}

double Movie::getAverageRating() const {
    if (ratings.empty()) return 0.0;
    double sum = accumulate(ratings.begin(), ratings.end(), 0.0);
    return sum / ratings.size();
}

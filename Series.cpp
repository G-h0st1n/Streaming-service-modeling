#include "Series.h"

Series::Series(int id, const string &name, int length, const string &genre,
               const vector<string> &episodes, int seasons)
    : Video(id, name, length, genre), episodes(episodes), seasons(seasons) {}

void Series::display() const {
    cout << "Series: " << name << "\n";
    cout << "Genre: " << genre << "\n";
    cout << "Seasons: " << seasons << "\n";
    cout << "Episodes:\n";
    for (const auto &episode : episodes) {
        cout << "  - " << episode << "\n"; // Each episode on a new line
    }
    cout << "Average Rating: " << getAverageRating() << "\n";
}

void Series::addRating(double rating) {
    if (rating >= 1.0 && rating <= 5.0) {
        ratings.push_back(rating);
    }
}

double Series::getAverageRating() const {
    if (ratings.empty()) return 0.0;
    double sum = accumulate(ratings.begin(), ratings.end(), 0.0);
    return sum / ratings.size();
}

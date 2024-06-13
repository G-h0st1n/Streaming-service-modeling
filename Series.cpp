#include "Series.h"
#include <iostream>
using namespace std;

Series::Series(int id, const string &name, int length, const string &genre, const vector<string> &episodes, int seasons)
    : Video(id, name, length, genre), episodes(episodes), seasons(seasons) {}

void Series::display() const {
    cout << "Series: " << name << " (" << genre << ") - " << length << " episodes. Rating: " << getAverageRating() << endl;
}

void Series::displayEpisodes() const {
    cout << "Episodes of " << name << ":" << endl;
    for (const auto &episode : episodes) {
        cout << " - " << episode << endl;
    }
}

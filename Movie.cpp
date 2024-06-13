#include "Movie.h"
#include <iostream>
using namespace std;

Movie::Movie(int id, const string &name, int length, const string &genre)
    : Video(id, name, length, genre) {}

void Movie::display() const {
    cout << "Movie: " << name << " (" << genre << ") - " << length << " minutes. Rating: " << getAverageRating() << endl;
}

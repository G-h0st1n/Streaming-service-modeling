#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class Video {
protected:
    int id;
    string name;
    int length; // in minutes
    string genre;
    vector<int> ratings;

public:
    Video(int id, const string &name, int length, const string &genre);
    virtual ~Video() = default;

    void addRating(int rating);
    double getAverageRating() const;

    virtual void display() const = 0; // Pure virtual function
};

#endif // VIDEO_H

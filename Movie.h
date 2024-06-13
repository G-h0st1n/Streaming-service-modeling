#ifndef MOVIE_H
#define MOVIE_H

#include "Video.h"
#include <vector>
#include <string>

class Movie : public Video {
public:
    Movie(int id, const std::string &name, int length, const std::string &genre);

    void display() const override;

    void addRating(double rating);
    double getAverageRating() const;
};

#endif // MOVIE_H

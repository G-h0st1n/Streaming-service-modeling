#ifndef MOVIE_H
#define MOVIE_H

#include "Video.h"

class Movie : public Video {
public:
    Movie(int id, const string &name, int length, const string &genre);
    void display() const override;
};

#endif // MOVIE_H

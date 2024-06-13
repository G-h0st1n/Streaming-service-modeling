#ifndef SERIES_H
#define SERIES_H

#include "Video.h"
#include <vector>

class Series : public Video {
private:
    vector<string> episodes;
    int seasons;

public:
    Series(int id, const string &name, int length, const string &genre, const vector<string> &episodes, int seasons);
    void display() const override;
    void displayEpisodes() const;
};

#endif // SERIES_H

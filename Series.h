#ifndef SERIES_H
#define SERIES_H

#include "Video.h"
#include <vector>
#include <string>

class Series : public Video {
    std::vector<std::string> episodes;
    int seasons;

public:
    Series(int id, const std::string &name, int length, const std::string &genre, const std::vector<std::string> &episodes, int seasons);

    void display() const override;
    void displayEpisodes() const;
};

#endif // SERIES_H

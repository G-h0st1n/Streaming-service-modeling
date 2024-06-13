#include <iostream>
#include <vector>
#include <memory>
#include "Movie.h"
#include "Series.h"

using namespace std;

int main() {
    vector<shared_ptr<Video>> videos;

    // Create some movies and series
    shared_ptr<Movie> movie1 = make_shared<Movie>(1, "Inception", 148, "Sci-Fi");
    shared_ptr<Movie> movie2 = make_shared<Movie>(2, "The Dark Knight", 152, "Action");
    vector<string> gotEpisodes = {"Winter Is Coming", "The Kingsroad", "Lord Snow"};
    shared_ptr<Series> series1 = make_shared<Series>(3, "Game of Thrones", 73, "Fantasy", gotEpisodes, 8);

    // Add ratings to the movies and series
    movie1->addRating(5);
    movie1->addRating(4);
    movie1->addRating(3);
    
    movie2->addRating(5);
    movie2->addRating(5);
    movie2->addRating(4);
    
    series1->addRating(4);
    series1->addRating(5);
    series1->addRating(5);

    // Add movies and series to the collection
    videos.push_back(movie1);
    videos.push_back(movie2);
    videos.push_back(series1);

    // Display all videos and their ratings
    for (const auto &video : videos) {
        video->display();
    }

    // Display episodes of a specific series
    series1->displayEpisodes();

    return 0;
}

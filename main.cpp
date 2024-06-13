#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include <string>
#include "Movie.h"
#include "Series.h"

using namespace std;

// Function to remove BOM if present
void removeBOM(string &line) {
    if (line.size() >= 3 && line[0] == '\xEF' && line[1] == '\xBB' && line[2] == '\xBF') {
        line.erase(0, 3);
    }
}

// Function to read movies from CSV file
vector<shared_ptr<Video>> readMovies(const string &filename) {
    vector<shared_ptr<Video>> movies;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        removeBOM(line);
        stringstream ss(line);
        string id, name, length, genre, ratings;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, length, ',');
        getline(ss, genre, ',');
        getline(ss, ratings, ',');

        try {
            int movieId = stoi(id);
            int movieLength = stoi(length);
            shared_ptr<Movie> movie = make_shared<Movie>(movieId, name, movieLength, genre);

            stringstream ratingsStream(ratings);
            string rating;
            while (getline(ratingsStream, rating, ';')) {
                try {
                    movie->addRating(stoi(rating));
                } catch (const invalid_argument &) {
                    cerr << "Invalid rating: " << rating << " for movie " << name << endl;
                }
            }
            movies.push_back(movie);
        } catch (const invalid_argument &e) {
            cerr << "Invalid argument while processing line: " << line << " - " << e.what() << endl;
        } catch (const out_of_range &e) {
            cerr << "Out of range error while processing line: " << line << " - " << e.what() << endl;
        }
    }
    return movies;
}

// Function to read series from CSV file
vector<shared_ptr<Video>> readSeries(const string &filename) {
    vector<shared_ptr<Video>> seriesList;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        removeBOM(line);
        stringstream ss(line);
        string id, name, length, genre, episodes, seasons, ratings;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, length, ',');
        getline(ss, genre, ',');
        getline(ss, episodes, ',');
        getline(ss, seasons, ',');
        getline(ss, ratings, ',');

        try {
            int seriesId = stoi(id);
            int seriesLength = stoi(length);
            int seriesSeasons = stoi(seasons);
            
            vector<string> episodeList;
            stringstream episodesStream(episodes);
            string episode;
            while (getline(episodesStream, episode, '|')) {
                episodeList.push_back(episode);
            }

            shared_ptr<Series> series = make_shared<Series>(seriesId, name, seriesLength, genre, episodeList, seriesSeasons);
            
            stringstream ratingsStream(ratings);
            string rating;
            while (getline(ratingsStream, rating, ';')) {
                try {
                    series->addRating(stoi(rating));
                } catch (const invalid_argument &) {
                    cerr << "Invalid rating: " << rating << " for series " << name << endl;
                }
            }
            seriesList.push_back(series);
        } catch (const invalid_argument &e) {
            cerr << "Invalid argument while processing line: " << line << " - " << e.what() << endl;
        } catch (const out_of_range &e) {
            cerr << "Out of range error while processing line: " << line << " - " << e.what() << endl;
        }
    }
    return seriesList;
}

void displayMenu() {
    cout << "Welcome to the archives, what is your inquiry?" << endl;
    cout << "Press M to see the movies or S for the series: ";
}

void displayMovies(const vector<shared_ptr<Video>> &movies) {
    cout << "Movies:" << endl;
    for (size_t i = 0; i < movies.size(); ++i) {
        cout << i + 1 << ". ";
        movies[i]->display();
    }
}

void displaySeries(const vector<shared_ptr<Video>> &seriesList) {
    cout << "Series:" << endl;
    for (size_t i = 0; i < seriesList.size(); ++i) {
        cout << i + 1 << ". ";
        seriesList[i]->display();
    }
}

int main() {
    vector<shared_ptr<Video>> movies = readMovies("Movies.csv");
    vector<shared_ptr<Video>> seriesList = readSeries("Series.csv");

    char choice;
    do {
        displayMenu();
        cin >> choice;

        if (choice == 'M' || choice == 'm') {
            displayMovies(movies);
        } else if (choice == 'S' || choice == 's') {
            displaySeries(seriesList);

            cout << "Enter the number of the series to inquire further or 0 to go back: ";
            int seriesChoice;
            cin >> seriesChoice;
            if (seriesChoice > 0 && seriesChoice <= seriesList.size()) {
                auto series = dynamic_pointer_cast<Series>(seriesList[seriesChoice - 1]);
                if (series) {
                    series->displayEpisodes();
                }
            }
        }
    } while (choice != 'Q' && choice != 'q');

    return 0;
}

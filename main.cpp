#include "Movie.h"
#include "Series.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>

using namespace std;

vector<Video*> loadMovies(const string& filename) {
    vector<Video*> movies;
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Could not open file");
    }

    string line;
    getline(file, line); // Skip header

    while (getline(file, line)) {
        if (line.empty()) continue; // Skip empty lines

        stringstream ss(line);
        string idStr, name, lengthStr, genre, ratingsStr;
        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, lengthStr, ',');
        getline(ss, genre, ',');
        getline(ss, ratingsStr, ',');

        try {
            int id = stoi(idStr);
            int length = stoi(lengthStr);

            Movie* movie = new Movie(id, name, length, genre);

            stringstream ratingsStream(ratingsStr);
            string rating;
            while (getline(ratingsStream, rating, ';')) {
                if (!rating.empty()) {
                    movie->addRating(stod(rating));
                }
            }

            movies.push_back(movie);
        } catch (const invalid_argument& e) {
            cerr << "Invalid argument while processing line: " << line << " - " << e.what() << endl;
        }
    }

    return movies;
}

vector<Video*> loadSeries(const string& filename) {
    vector<Video*> seriesList;
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Could not open file");
    }

    string line;
    getline(file, line); // Skip header

    while (getline(file, line)) {
        if (line.empty()) continue; // Skip empty lines

        stringstream ss(line);
        string idStr, name, lengthStr, genre, episodesStr, seasonsStr, ratingsStr;
        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, lengthStr, ',');
        getline(ss, genre, ',');
        getline(ss, episodesStr, ',');
        getline(ss, seasonsStr, ',');
        getline(ss, ratingsStr, ',');

        try {
            int id = stoi(idStr);
            int length = stoi(lengthStr);
            int seasons = stoi(seasonsStr);

            vector<string> episodes;
            stringstream episodesStream(episodesStr);
            string episode;
            while (getline(episodesStream, episode, ';')) {
                episodes.push_back(episode);
            }

            Series* series = new Series(id, name, length, genre, episodes, seasons);

            stringstream ratingsStream(ratingsStr);
            string rating;
            while (getline(ratingsStream, rating, ';')) {
                if (!rating.empty()) {
                    series->addRating(stod(rating));
                }
            }

            seriesList.push_back(series);
        } catch (const invalid_argument& e) {
            cerr << "Invalid argument while processing line: " << line << " - " << e.what() << endl;
        }
    }

    return seriesList;
}

void displayMenu() {
    cout << "Welcome to the archives, what is your inquiry?\n";
    cout << "Press M to see the movies or S for the series: ";
}

void displayMovies(const vector<Video*>& movies) {
    cout << "Movies:\n";
    for (size_t i = 0; i < movies.size(); ++i) {
        cout << i + 1 << ". " << movies[i]->getName() << "\n";
    }
}

void displaySeries(const vector<Video*>& seriesList) {
    cout << "Series:\n";
    for (size_t i = 0; i < seriesList.size(); ++i) {
        cout << i + 1 << ". " << seriesList[i]->getName() << "\n";
    }
}

int main() {
    try {
        vector<Video*> movies = loadMovies("Movies.csv");
        vector<Video*> seriesList = loadSeries("Series.csv");

        char choice;
        do {
            displayMenu();
            cin >> choice;
            choice = toupper(choice);

            if (choice == 'M') {
                displayMovies(movies);
                cout << "Enter the number of the movie to inquire further or 0 to go back: ";
                int selection;
                cin >> selection;
                if (selection > 0 && selection <= static_cast<int>(movies.size())) {
                    movies[selection - 1]->display();
                }
            } else if (choice == 'S') {
                displaySeries(seriesList);
                cout << "Enter the number of the series to inquire further or 0 to go back: ";
                int selection;
                cin >> selection;
                if (selection > 0 && selection <= static_cast<int>(seriesList.size())) {
                    seriesList[selection - 1]->display();
                }
            }
        } while (choice == 'M' || choice == 'S');

        // Clean up
        for (Video* video : movies) {
            delete video;
        }
        for (Video* video : seriesList) {
            delete video;
        }

    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
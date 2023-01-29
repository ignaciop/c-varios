#include <iostream>
#include <string>
#include <cmath>

struct MovieData {
    std::string title;
    std::string director;
    int release_year;
    double running_time;

    MovieData(std::string inputTitle, std::string inputDirector, int inputReleaseYear, double inputRunningTime)
        : title(inputTitle), director(inputDirector), release_year(inputReleaseYear), running_time(inputRunningTime) {};
};

void displayMovieData(std::string title, std::string director, int release_year, double running_time);

int main() {
    MovieData m1("Titanic", "James Cameron", 1997, 160.0);
    MovieData m2("Good Will Hunting", "Gus Van Sant", 1997, 126.0);

    displayMovieData(m1.title, m1.director, m1.release_year, m1.running_time);
    displayMovieData(m2.title, m2.director, m2.release_year, m2.running_time);
        
    return 0;
}

void displayMovieData(std::string title, std::string director, int release_year, double running_time) {
    std::cout << "\"" << title << "\" (" << release_year << ")"
                << ", directed by " << director << ". Duration: "
                    << running_time << " minutes." << std::endl;
}
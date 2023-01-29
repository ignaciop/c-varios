#include <iostream>
#include <string>
#include <cmath>

struct MovieData {
    std::string title;
    std::string director;
    int release_year;
    double running_time;
    double production_cost;
    double fy_revenues;

    MovieData(std::string inputTitle, std::string inputDirector, int inputReleaseYear, double inputRunningTime, double inputProductionCost, double inputFYRevenues)
        : title(inputTitle), director(inputDirector), release_year(inputReleaseYear), running_time(inputRunningTime), production_cost(inputProductionCost), fy_revenues(inputFYRevenues) {};
};

void displayMovieData(const std::string &title, const std::string &director, const int &release_year, const double &running_time, double &production_cost, double &fy_revenues);

int main() {
    MovieData m1("Titanic", "James Cameron", 1997, 160.0, 2e8, 1.8e9);
    MovieData m2("Invented Movie", "John Doe", 2022, 45.0, 1e5, 1e2);

    displayMovieData(m1.title, m1.director, m1.release_year, m1.running_time, m1.production_cost, m1.fy_revenues);
    displayMovieData(m2.title, m2.director, m2.release_year, m2.running_time, m2.production_cost, m2.fy_revenues);
        
    return 0;
}

void displayMovieData(const std::string &title, const std::string &director, const int &release_year, const double &running_time, double &production_cost, double &fy_revenues) {
    std::cout << "\"" << title << "\" (" << release_year << ")"
                << ", directed by " << director << ". Duration: "
                    << running_time << " minutes." << std::endl;
    
    double money = fy_revenues - production_cost;

    std::cout << "$" << fabs(money) << ((money < 0) ? " loss." : " profit.") << std::endl;
}
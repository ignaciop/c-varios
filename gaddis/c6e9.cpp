#include <iostream>
#include <iomanip>
  
void getScore(int &);
void calcAverage(int, int, int, int, int);
int findLowest(int, int, int, int, int);
         
int main() {
    int testScr1, testScr2, testScr3, testScr4, testScr5;
         
    getScore(testScr1);
    getScore(testScr2);
    getScore(testScr3);
    getScore(testScr4);
    getScore(testScr5);

    calcAverage(testScr1, testScr2, testScr3, testScr4, testScr5);
    
    return 0;
}
  
void getScore(int &score) {
    std::cout << "Enter a test score\n";
    std::cin >> score;
         
    while (score < 0 || score > 100) {
        std::cout << "Please enter a valid test score that between 0 to 100\n";
        std::cin >> score;
    }
}
  
void calcAverage(int s1, int s2, int s3, int s4, int s5) {
    int sum;
    int lowest;
    double average;

    lowest = findLowest(s1, s2, s3, s4, s5);
    sum = s1 + s2 + s3 + s4 + s5 - lowest;
    average = sum/4.0;

    std::cout << std::setw(4) << std::fixed << std::showpoint << std::setprecision(2);
    std::cout << "The average of the four highest scores are: " << average << std::endl;
}
  
int findLowest(int s1, int s2, int s3, int s4, int s5) {
    int lowest = s1; 
         
    if (s2 < lowest) {
        lowest = s2;
    } else if (s3 < lowest) {
        lowest = s3;
    } else if (s4 < lowest) {
        lowest = s4;
    } else if (s5 < lowest) {
        lowest = s5;
    }
    
    std::cout << "The lowest test score is: " << lowest << std::endl;
  
    return lowest;
}
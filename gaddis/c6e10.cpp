#include <iostream>
#include <iomanip>
  
void getJudgeData(double &);
void calcScore(double, double, double, double, double);
double findLowest(double, double, double, double, double);
double findHighest(double, double, double, double, double);
    
int main() {
    double testScr1, testScr2, testScr3, testScr4, testScr5;
         
    getJudgeData(testScr1);
    getJudgeData(testScr2);
    getJudgeData(testScr3);
    getJudgeData(testScr4);
    getJudgeData(testScr5);

    calcScore(testScr1, testScr2, testScr3, testScr4, testScr5);
    
    return 0;
}
  
void getJudgeData(double &score) {
    std::cout << "Enter a score\n";
    std::cin >> score;
         
    while (score < 0 || score > 10) {
        std::cout << "Please enter a valid test score that between 0 to 100\n";
        std::cin >> score;
    }
}
  
void calcScore(double s1, double s2, double s3, double s4, double s5) {
    double sum;
    double lowest;
    double highest;
    double average;

    lowest = findLowest(s1, s2, s3, s4, s5);
    highest = findHighest(s1, s2, s3, s4, s5);
    sum = s1 + s2 + s3 + s4 + s5 - lowest - highest;
    average = sum / 3.0;

    std::cout << std::setw(4) << std::fixed << std::showpoint << std::setprecision(2);
    std::cout << "The average of the three middle scores are: " << average << std::endl;
}
  
double findLowest(double s1, double s2, double s3, double s4, double s5) {
    double lowest = s1; 
         
    if (s2 < lowest) {
        lowest = s2;
    } else if (s3 < lowest) {
        lowest = s3;
    } else if (s4 < lowest) {
        lowest = s4;
    } else if (s5 < lowest) {
        lowest = s5;
    }
    
    std::cout << "The lowest score is: " << lowest << std::endl;
  
    return lowest;
}

double findHighest(double s1, double s2, double s3, double s4, double s5) {
    double highest = s1; 
         
    if (s2 > highest) {
        highest = s2;
    } else if (s3 > highest) {
        highest = s3;
    } else if (s4 > highest) {
        highest = s4;
    } else if (s5 > highest) {
        highest = s5;
    }
    
    std::cout << "The highest score is: " << highest << std::endl;
  
    return highest;
}
#include <iostream>
#include <string>

int sum_units_sold(int jars_sold[], int size);
void calculateMaxAndMin(int jars_sold[], int size, int &indexMax, int &indexMin);
void displayReport(std::string salsa_names[], int jars_sold[], int size, int indexMax, int indexMin, int total_sold);

int main() {
    const int ARRAY_SIZE = 5;

    std::string	salsa_names[ARRAY_SIZE] = {"mild", "medium", "sweet", "hot", "zesty"};
    int jars_sold[ARRAY_SIZE] = {};

    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << "Units of " << salsa_names[i] << " sold? ";
        std::cin >> jars_sold[i];
    }

    int indexMax = 0;
    int indexMin = 0;
    int total_sold = sum_units_sold(jars_sold, ARRAY_SIZE);

    calculateMaxAndMin(jars_sold, ARRAY_SIZE, indexMax, indexMin);
    displayReport(salsa_names, jars_sold, ARRAY_SIZE, indexMax, indexMin, total_sold);

	return 0;
}

int sum_units_sold(int jars_sold[], int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += jars_sold[i];
    }

    return sum;
}

void calculateMaxAndMin(int jars_sold[], int size, int &indexMax, int &indexMin) {
    int max = jars_sold[0];
    int min = jars_sold[0];

    for (int i = 0; i < size; i++) {
        if (jars_sold[i] > max) {
            max = jars_sold[i];
            indexMax = i;
        }

        if (jars_sold[i] < min) {
            min = jars_sold[i];
            indexMin = i;
        }
    }
}

void displayReport(std::string salsa_names[], int jars_sold[], int size, int indexMax, int indexMin, int total_sold) {
    for (int i = 0; i < size; i++) {
        std::cout << "\nUnits sold of " << salsa_names[i] << ": " << jars_sold[i] << std::endl;
    }

    std::cout << "\nTotal units sold: " << total_sold << std::endl;
    std::cout << "Highest selling: " << salsa_names[indexMax] << std::endl;
    std::cout << "Lowest selling: " << salsa_names[indexMin] << std::endl;
}
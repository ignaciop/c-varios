#include <iostream>
#include <ctime>

using namespace std;

int main() {
    float M, initial_temperature, final_temperature;

    cout << "Enter the amount of water in kilograms: ";
    cin >> M;

    cout << "Enter the initial temperature: ";
    cin >> initial_temperature;

    cout << "Enter the final temperature: ";
    cin >> final_temperature;

    float Q = M * (final_temperature - initial_temperature) * 4184;
    
    cout << "The energy needed is " << Q << "\n";

    return 0;
}
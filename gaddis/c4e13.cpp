#include <iostream>
#include <string>

int main() {
    std::cout << "Name of runner: ";
    std::string r1 = "";
    getline(std::cin, r1);

    std::cout << "Time to finish the race: ";
    double t1 = 0.0;
    std::cin >> t1;

    std::cin.ignore();

    std::cout << "Name of runner: ";
    std::string r2 = "";
    getline(std::cin, r2);

    std::cout << "Time to finish the race: ";
    double t2 = 0.0;
    std::cin >> t2;

    std::cin.ignore();

    std::cout << "Name of runner: ";
    std::string r3 = "";
    getline(std::cin, r3);

    std::cout << "Time to finish the race: ";
    double t3 = 0.0;
    std::cin >> t3;

    if (t1 < 0 || t2 < 0 || t3 < 0) {
        std::cout << "Please re-run the program with valid times." << std::endl;

        return 0;
    }

    if (t1 < t2) {
        if (t2 < t3) {
            std::cout << "1º. " << r1 << std::endl;
            std::cout << "2º. " << r2 << std::endl;
            std::cout << "3º. " << r3 << std::endl;
        } else {
            if (t3 < t1) {
                std::cout << "1º. " << r3 << std::endl;
                std::cout << "2º. " << r1 << std::endl;
                std::cout << "3º. " << r2 << std::endl;
            } else {
                std::cout << "1º. " << r1 << std::endl;
                std::cout << "2º. " << r3 << std::endl;
                std::cout << "3º. " << r2 << std::endl;
            }
        }
    } else {
        if (t1 < t3) {
            std::cout << "1º. " << r2 << std::endl;
            std::cout << "2º. " << r1 << std::endl;
            std::cout << "3º. " << r3 << std::endl;
        } else {
            if (t3 < t2) {
                std::cout << "1º. " << r3 << std::endl;
                std::cout << "2º. " << r2 << std::endl;
                std::cout << "3º. " << r1 << std::endl;
            } else {
                std::cout << "1º. " << r2 << std::endl;
                std::cout << "2º. " << r3 << std::endl;
                std::cout << "3º. " << r1 << std::endl;
            }
        }
    }

    return 0;
}
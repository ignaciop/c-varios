#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> strings;
    std::vector<int> values;
    std::string s;

    while (true) {
        std::cout << "Enter strings delimited by an enter: ";
        getline(std::cin, s);

        if (s != "***") {
            strings.push_back(s); 
        } else {
            break;
        }
    }
    
    for (auto it = strings.begin(); it != strings.end(); it++) {
        std::string temp = *it;
        int sum = 0;
        int num = 0;

        for (int i = 0; i < temp.length(); i++) {
            switch (temp[i]) {
            case 'a':
                num = 1;
                break;
            case 'b':
                num = 2;
                break;
            case 'c':
                num = 3;
                break;
            case 'd':
                num = 4;
                break;
            case 'e':
                num = 5;
                break;
            case 'f':
                num = 6;
                break;
            case 'g':
                num = 7;
                break;
            case 'h':
                num = 8;
                break;
            case 'i':
                num = 9;
                break;
            case 'j':
                num = 10;
                break;
            case 'k':
                num = 20;
                break;
            case 'l':
                num = 30;
                break;
            case 'm':
                num = 40;
                break;
            case 'n':
                num = 50;
                break;
            case 'o':
                num = 60;
                break;
            case 'p':
                num = 70;
                break;
            case 'q':
                num = 80;
                break;
            case 'r':
                num = 90;
                break;
            case 's':
                num = 100;
                break;
            case 't':
                num = 200;
                break;
            case 'u':
                num = 300;
                break;
            case 'v':
                num = 400;
                break;
            case 'w':
                num = 500;
                break;
            case 'x':
                num = 600;
                break;
            case 'y':
                num = 700;
                break;
            case 'z':
                num = 800;
                break;
            default:
                num = 0;
                break;
            }

            sum += num;
        }

        values.push_back(sum); 
    }

    int max = values[0];
    int min = values[0];
    int pos_max_index = 0;
    int pos_min_index = 0;

    for (auto it = values.begin(); it != values.end(); it++) {
        if (*it >= max) {
            max = *it;
            pos_max_index = it - values.begin();
        }

        if (*it <= min) {
            min = *it;
            pos_min_index = it - values.begin();
        }
    }

    std::cout << "\nString with maximum value: " 
                << strings[pos_max_index] << " --> " << max << std::endl;
    std::cout << "\nString with minimum value: " 
                << strings[pos_min_index] << " --> " << min << std::endl;

    return 0;
}
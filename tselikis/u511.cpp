#include <iostream>

int main() {
    std::cout << "Enter four integers: ";
    int a, b, c, d = 0;
    std::cin >> a >> b >> c >> d;

    int left_max = (a < b) ? b : a;
    int right_max = (c < d) ? d : c;
    int final_max = (left_max < right_max) ? right_max : left_max;
    
    std::cout << final_max << "+" << right_max << "=" << final_max + right_max
                << std::endl;

    return 0;
}
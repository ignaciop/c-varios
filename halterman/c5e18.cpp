#include <iostream>

int main() {
    std::cout << "Enter five integers: ";
    int a {}, b {}, c {}, d {}, e {};
    std::cin >> a >> b >> c >> d >> e;

    int largest {};
    int smallest {};

    if ((a >= b) && (a >= c) && (a >= d) && (a >= e)) {    
        largest = a;
    } else if ((b >= a) && (b >= c) && (b >= d) && (b >= e)) {    
        largest = b;
    } else if ((c >= a) && (c >= a) && (c >= d) && (c >= e)) {    
        largest = c;
    } else if ((d >= a) && (d >= c) && (d >= a) && (d >= e)) {    
        largest = d;
    } else {
        largest = e;
    }

    if ((a <= b) && (a <= c) && (a <= d) && (a <= e)) {    
        smallest = a;
    } else if ((b <= a) && (b <= c) && (b <= d) && (b <= e)) {    
        smallest = b;
    } else if ((c <= a) && (c <= a) && (c <= d) && (c <= e)) {    
        smallest = c;
    } else if ((d <= a) && (d <= c) && (d <= a) && (d <= e)) {    
        smallest = d;
    } else {
        smallest = e;
    }

    std::cout << "Maximum: " << largest << std::endl;
    std::cout << "Minimum: " << smallest << std::endl;

    return 0;
}
#include <iostream>

int main() {
	double x;
	double y;
	char operand;
	
	std::cout << "Enter a double value: ";
	std::cin >> x;
	std::cout << "Enter a double value: ";
	std::cin >> y;
	std::cout << "Enter one of the following: +, -, *, or /: ";
	std::cin >> operand;
	
	if (operand == '+') {
		std::cout << x << " + " << y << " is " << x+y << std::endl;
	} else 	if (operand == '-') {
		std::cout << x << " - " << y << " is " << x-y << std::endl;
	} else if (operand == '*') {
		std::cout << x << " * " << y << " is " << x*y << std::endl;
	} else if (operand == '/') {
		std::cout << x << " / " << y << " is " << x/y << std::endl;	
	}
	
	return 0;
}
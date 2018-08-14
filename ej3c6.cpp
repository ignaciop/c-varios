#include <iostream>

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	std::cout << "Enter a: ";
	int a;
	std::cin >> a;
	std::cout << "Enter b: ";
	int b;
	std::cin >> b;
	
	std::cout << "Before swap --> " << "a = " << a << ", b = " << b << std::endl;
	swap(a,b);
	std::cout << "After swap --> " << "a = " << a << ", b = " << b << std::endl;
	
	return 0;
}
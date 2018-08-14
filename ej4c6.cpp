#include <iostream>

void printCString(const char *str) {
	while (*str != '\0') {
		std::cout << *str;
		++str;
	}
}

int main() {
	printCString("Hello world!");
	
	return 0;
}
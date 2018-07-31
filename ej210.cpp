#include <iostream>


int main() {
	int n = 10;
	int k = 0;
	
	while (k != n) {
		using std::cout;
		cout << "*";
		++k;
	}
	
	std::cout << std::endl;
	
	return 0;
}
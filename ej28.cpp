#include <iostream>

using namespace std;

int main() {
	int p = 1;
	
	for (int i = 1; i != 10; i++) {
		p = p*i;
	}
	
	cout << p << endl;
	
	return 0;
}
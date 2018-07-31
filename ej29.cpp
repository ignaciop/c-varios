#include <iostream>

using namespace std;

int main() {
	cout << "Enter first number: ";
	int n1;
	cin >> n1;
	
	cout << "Enter second number: ";
	int n2;
	cin >> n2;
	
	if (n1 == n2) {
		cout << n1 << " is equal to " << n2 << endl;
	} else {
		if (n1 > n2) {
			cout << n1 << " is larger than " << n2 << endl;
		} else {
			cout << n2 << " is larger than " << n1 << endl; 
		}
	}
	
	return 0;
}
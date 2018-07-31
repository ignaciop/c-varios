#include <iostream>
#include <string>

using namespace std;

int main() {
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	
	const string greeting = "Hello, " + name + "!";
	
	const int hpad = 1;
	const int rows = hpad * 2 + 3;
	const int vpad = 2;
	const string::size_type cols = greeting.size() + vpad * 2 + 2;
	
	cout << endl;
	
	for (int r = 0; r != rows; ++r) {
		string::size_type c = 0;
		
		while (c != cols) {
			if (r == hpad + 1 && c == vpad + 1) {
				cout << greeting;
				c += greeting.size();
			} else {
				if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
					cout << "*";
				} else {
					cout << " ";
				}
				++c;
			}
		}
		
		cout << endl;
	}
	return 0;
}
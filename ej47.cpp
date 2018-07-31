#include <iostream>
#include <vector>

using namespace std;

istream& read_numbers(istream& in, vector<double>& numbers) {
	if (in) {
		numbers.clear();
		double number;
		
		while (in >> number) {
			numbers.push_back(number);
		}
		
		in.clear();
	}
	return in;
}

int main() {
	vector<double> numbers;
	
	read_numbers(cin, numbers);
	
	double avg = 0.0;
	double sum = 0.0;
	
	for (vector<double>::size_type i = 0; i < numbers.size(); ++i) {
		sum += numbers[i];
	}
	
	avg = sum / numbers.size();
	
	cout << "Average: " << avg << endl;
	
	return 0;
}
#include <iostream>
#include <stdexcept>

class Fraction {
private:
	int m_num;
	int m_den;
	
public:
	Fraction(int num = 0, int den = 1) : m_num(num), m_den(den) {
		if (m_den == 0) {
			throw std::runtime_error("Invalid denominator");
		}
	}
	
	friend std::ostream& operator<<(std::ostream& out, const Fraction &f1);
};

std::ostream& operator<<(std::ostream& out, const Fraction &f1) {
	out << f1.m_num << "/" << f1.m_den;
	
	return out;
}

int main() {
	std::cout << "Enter the numerator: ";
	int numerator;
	std::cin >> numerator;
	
	std::cout << "Enter the denominator: ";
	int denominator;
	std::cin >> denominator;
	
	try {
		Fraction f(numerator, denominator);
		std::cout << "Your fraction is: " << f << '\n';
	} catch (std::exception&) {
		std::cout << "Your fraction has an invalid denominator.\n";
	}
	
	return 0;
}
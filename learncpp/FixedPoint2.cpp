#include <iostream>
#include <cstdlib>
#include <cmath>

class FixedPoint2 {
private:
	std::int16_t m_base;
	std::int8_t m_decimal;
	
public:
	FixedPoint2(std::int16_t base = 0, std::int8_t decimal = 0)
	 : m_base(base), m_decimal(decimal) {
		if (m_base < 0.0 || m_decimal < 0.0) {
			if (m_base > 0.0) {
				m_base = -m_base;
			}
			
			if (m_decimal > 0.0) {
				m_decimal = -m_decimal;
			}
		}
	}
	
	FixedPoint2(double d) {
		m_base = static_cast<int16_t>(d);
		m_decimal = static_cast<std::int8_t>(round((d - m_base)*100));
	}
	
	operator double() const {
		return m_base + static_cast<double>(m_decimal) / 100;
	}
	
	friend std::ostream& operator<<(std::ostream &out, const FixedPoint2 &fp) {
		out << static_cast<double>(fp);
		
		return out;
	}

	friend bool operator==(const FixedPoint2 &fp1, const FixedPoint2 &fp2) {
		return (fp1.m_base == fp2.m_base && fp1.m_decimal == fp2.m_decimal);
	}


	friend std::istream& operator>> (std::istream &in, FixedPoint2 &fp) {
		double d;
		in >> d;
		fp = FixedPoint2(d);

		return in;
	}

	friend FixedPoint2 operator+(const FixedPoint2 &fp1, const FixedPoint2 &fp2) {
		return FixedPoint2(static_cast<double>(fp1) + static_cast<double>(fp2));
	}

	FixedPoint2 operator-() {
		return FixedPoint2(-m_base, -m_decimal);
	}
};

void testAddition() {
	// h/t to reader Sharjeel Safdar for this function
	std::cout << std::boolalpha;
	std::cout << (FixedPoint2(0.75) + FixedPoint2(1.23) == FixedPoint2(1.98)) << '\n'; // both positive, no decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(1.50) == FixedPoint2(2.25)) << '\n'; // both positive, with decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.23) == FixedPoint2(-1.98)) << '\n'; // both negative, no decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.50) == FixedPoint2(-2.25)) << '\n'; // both negative, with decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.23) == FixedPoint2(-0.48)) << '\n'; // second negative, no decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.50) == FixedPoint2(-0.75)) << '\n'; // second negative, possible decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.23) == FixedPoint2(0.48)) << '\n'; // first negative, no decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.50) == FixedPoint2(0.75)) << '\n'; // first negative, possible decimal overflow
}

int main() {
	testAddition();
	
	FixedPoint2 a(-0.48);
	std::cout << a << '\n';
	std::cout << -a << '\n';
	
	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;
	
	std::cout << "You entered: " << a << '\n';
	
	

	return 0;
}
#include <iostream>

template<class T, class S>
class Pair1 {
private:
	T m_x;
	S m_y;
	
public:
	Pair1(const T& x, const S& y) : m_x(x), m_y(y) {}
	
	T& first() { return m_x; }
	const T& first() const { return m_x; }	
	S& second() { return m_y; }
	const S& second() const { return m_y; }
};

int main() {
	Pair1<int, double> p1(5, 6.7);
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
	
	const Pair1<double, int> p2(2.3, 4);
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}
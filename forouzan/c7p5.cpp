#include <iostream>
#include "classes/Triangle.h"

int main() {
    Triangle t1;

    double t1_fs = 0.0, t1_ss = 0.0, t1_ts = 0.0;

    t1.getSides(t1_fs, t1_ss, t1_ts);

    std::cout << "Perimeter of triangle with sides " << t1_fs << ", " << t1_ss
                << " and " << t1_ts << ": " << t1.getPerimeter() << std::endl;
    std::cout << "Area of triangle with sides " << t1_fs << ", " << t1_ss
                << " and " << t1_ts << ": " << t1.getArea() << std::endl;

    Triangle t2(2.5, 3.5, 5.5);

    double t2_fs = 0.0, t2_ss = 0.0, t2_ts = 0.0;

    t2.getSides(t2_fs, t2_ss, t2_ts);

    std::cout << "\nPerimeter of triangle with sides " << t2_fs << ", " << t2_ss
                << " and " << t2_ts << ": " << t2.getPerimeter() << std::endl;
    std::cout << "Area of triangle with sides " << t2_fs << ", " << t2_ss
                << " and " << t2_ts << ": " << t2.getArea() << std::endl;

    return 0;
}
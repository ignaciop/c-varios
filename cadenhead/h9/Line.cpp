#include <iostream>
#include "Point.h"

class Line {
    // no constructor, use default
public:
    void setPoint1(Point newPoint1) { point1 = newPoint1; }
    void setPoint2(Point newPoint2) { point2 = newPoint2; }
    Point getPoint1() { return point1; }
    Point getPoint2() { return point2; }
    void displayLine();
private:
    Point point1;
    Point point2;
};

// display information about the line
void Line::displayLine() {
    Point p1 = getPoint1();
    Point p2 = getPoint2();
    std::cout << "Line from (" << p1.getX() << "," << p1.getY() << ") to ";
    std::cout << "(" << p2.getX() << "," << p2.getY() << ")\n";
}

// create some points
int main() {
    Line l;
    Point p1;
    Point p2;
    
    p1.setX(50);
    p1.setY(35);
    
    p2.setX(45);
    p2.setY(13);
    
    l.setPoint1(p1);
    l.setPoint2(p2);
    
    l.displayLine();
    
    return 0;
}
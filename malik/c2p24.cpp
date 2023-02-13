#include <iostream>

using namespace std;

int main() {
    const double RATIO = 1.5;

    double wire_length, frame_width, frame_length;

    cout << "Enter the length of the wire: ";
    cin >> wire_length;

    frame_width = wire_length / 2;
    frame_length = RATIO * frame_width;

    cout << "Frame length: " << frame_length << endl;
    cout << "Frame width : " << frame_width << endl;
    
    return 0;
}
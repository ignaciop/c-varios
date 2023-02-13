#include <iostream>

using namespace std;

int main() {
    double doorLength, doorWidth, windowLength, windowWidth, bookshelfLength, bookshelfWidth, roomLength, roomWidth, roomHeight;
    double doorArea, windowArea, bookshelfArea, wallArea, totalArea;
    int gallonsNeeded;
    
    // Input length and width of door
    cout << "Enter the length of the door: ";
    cin >> doorLength;
    cout << "Enter the width of the door: ";
    cin >> doorWidth;
    
    // Calculate door area
    doorArea = doorLength * doorWidth;
    
    // Input length and width of first window
    cout << "Enter the length of the first window: ";
    cin >> windowLength;
    cout << "Enter the width of the first window: ";
    cin >> windowWidth;
    
    // Calculate first window area
    windowArea = windowLength * windowWidth;
    
    // Input length and width of second window
    cout << "Enter the length of the second window: ";
    cin >> windowLength;
    cout << "Enter the width of the second window: ";
    cin >> windowWidth;
    
    // Calculate second window area
    windowArea += windowLength * windowWidth;
    
    // Input length and width of bookshelf
    cout << "Enter the length of the bookshelf: ";
    cin >> bookshelfLength;
    cout << "Enter the width of the bookshelf: ";
    cin >> bookshelfWidth;
    
    // Calculate bookshelf area
    bookshelfArea = bookshelfLength * bookshelfWidth;
    
    // Input length, width, and height of room
    cout << "Enter the length of the room: ";
    cin >> roomLength;
    cout << "Enter the width of the room: ";
    cin >> roomWidth;
    cout << "Enter the height of the room: ";
    cin >> roomHeight;
    
    // Calculate total wall area
    wallArea = 2 * (roomLength * roomHeight) + 2 * (roomWidth * roomHeight);
    
    // Subtract door, window, and bookshelf areas from wall area
    totalArea = wallArea - (doorArea + windowArea + bookshelfArea);
    
    // Calculate number of gallons needed to paint room
    gallonsNeeded = totalArea / 120;
    
    // Output number of gallons needed
    cout << "The number of gallons needed to paint the room is: " << gallonsNeeded << endl;
    
    return 0;
}

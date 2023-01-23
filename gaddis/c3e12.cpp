#include <iostream>

int main() {
    const int COOKIES = 30;
    const int SERVINGS = 10;
    const int CALORIES_PER_SERVING = 240;

    int cookies_per_serving = COOKIES / SERVINGS;
    int calories_per_cookie = CALORIES_PER_SERVING / cookies_per_serving;

    std::cout << "How many cookies you ate? ";
    int cookies_eaten = 0;
    std::cin >> cookies_eaten;

    int calories_eaten = cookies_eaten * calories_per_cookie;

    std::cout << "Calories eaten: " << calories_eaten << " cals." << std::endl;
    
    return 0;
}
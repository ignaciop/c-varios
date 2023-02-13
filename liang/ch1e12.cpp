#include <iostream>

using namespace std;

int main() {
    cout << "A vendor sells 5553 grams of grocery in 2 hours, 9 minutes and 30 seconds.\n";

    cout << "Per hour, sells: " << 5553.0/(2 + 9/60 + (30/60)/60) << " grams.\n";
            
    return 0;
}
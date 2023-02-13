#include <iostream>

using namespace std;

int main() {
    cout << "A vendor sells 6 kg of grocery in 15 hours, 30 minutes and 30 seconds.\n";

    cout << "Per hour, sells: " << 6000.0/(15 + 30/60 + (30/60)/60) << " grams.\n";
            
    return 0;
}
#include <iostream>
#include <string>

int main() {

	const int romanNum = 21;	
	const int SENTINEL = 0;		

	int num = 1;	        	

	std::string	roman[romanNum] =	{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", 
									"XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XIII", "XIX", "XX"};

	do {
		std::cout << "Please enter a number between 1 and " << romanNum - 1 << " (Enter 0 to stop): ";
		
        if (!(std::cin >> num)) {
			std::cout << "Entry is not a number" << std::endl;
			std::cin.clear();
			std::cin.ignore(100, '\n');
		} else {
			if (num > 0 && num < romanNum) {
				std:: cout << num << " is equivalent to " << roman[num] << std::endl;   
            } else {
				if (num != SENTINEL) {
					std::cout << "Invalid number\n";
                }
            }
        }
	
	} while (num != SENTINEL);

	return 0;
}
#include <iostream>
#include <iomanip>

int main() {
	// Create a two-dimensional 3x7 array.
	const int mkys = 3;
	const int days = 7;
	int food[mkys][days];
	double pounds, least, most, sum = 0;
	
	// Ask user to input data for each monkey
	std::cout << "Input how many pounds of food each monkey ate each day.\n";
	
    for (int row = 0; row < mkys; row++) {
		for (int col = 0; col < days; col++) {
			do {
				std::cout << "Monkey #" << (row + 1) << " on day #" << (col + 1)
					 << " ate: ";
				std::cin  >> pounds;

				if (pounds < 0) {
					std::cout << "Error! Number of pounds must be greater than 0.\n";
				}

			} while (pounds < 0);

			food[row][col] = pounds;

			// Get total food eaten per day by the whole family of monkeys.
			sum += pounds;
		}

		std::cout << std::endl;							// make blank space
	}

	// Get least and greatest amount of food eaten by any one monkey.
	least = most = food[0][0];

	for (int row = 0; row < mkys; row++){
		for (int col = 0; col < days; col++){	
			if (food[row][col] < least) { 
				least = food[row][col];
			}

			if (food[row][col] > most) { 
				most = food[row][col];
			}
		}
	}

	std::cout << "\n             Monkey Weekly Food Report\n"
		 << "             by the whole family of monkeys\n"
		 << "----------------------------------------------------\n";
	std::cout << std::fixed << std::showpoint << std::setprecision(1);
	std::cout << "Average amount of food eaten per day : "
		 << sum / 21.0 << " pounds.\n";
	std::cout << "Least amount of food eaten: " << least << " pounds.\n";
	std::cout << "Greatest amount of food eaten: " << most << " pounds.\n";

	return 0;
}
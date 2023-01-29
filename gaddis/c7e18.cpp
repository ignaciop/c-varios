#include <iostream>
#include "classes/Dice.h"
#include <string>

int main() {
	const int DIE1_SIDES = 6;
	Dice die1(DIE1_SIDES);
	int huge = 20, old = -7, tiny = 5, normal = 10, mud = -1, toilet = -20;
	int hugeT = 0, oldT = 0, tinyT = 0, normalT = 0, mudT = 0, toiletT = 0, round = 0;
	double total = 0;
	char choice;
	std::string fish, Tround;
	

	std::cout<< "*****************************************************************************\n";
	std::cout<< "*                         FISHING GAME SIMULATOR                            *\n";
	std::cout<< "*****************************************************************************\n";
	std::cout<< "*            This game simulates fishing and uses a random number           *\n";
	std::cout<< "*             between 1 and 6 to determine what type of fish you            *\n";
	std::cout<< "*           have have hooked. It will also display what you caught          *\n";
	std::cout<< "*          and the points awarded when you decide to leave the game.        *\n";
	std::cout<< "*                         Have fun and good luck!                           *\n";
	std::cout<< "*****************************************************************************\n";

	std::cout<<"\t\t Would you like to play the fishing game?\n";
	std::cout<<"\t\t   Please enter Y for YES or N for NO :";

	std::cin >> choice;

	while (true) {
        if (choice == 'n' || choice =='N') {
            break;
        } else {
            die1.roll();

		    if (die1.getValue() == 1) {
			    fish = "HUGE FISH";
			    total += huge;
			    round = huge;
			    hugeT++;
		    }
		
            if (die1.getValue() == 2) {
				fish = "Old Shoe";
				total +=old;
				round = old;
				oldT++;
		    }
			
            if (die1.getValue() == 3) {
				fish = "Tiny Fish";
				total +=tiny;
				round = tiny;
				tinyT++;
		    }
		
            if (die1.getValue() == 4) {
				fish = "Normal Sized Fish";
				total +=normal;
				round = normal;
				normalT++;
		    }
		
            if (die1.getValue() == 5) {
				fish = "Mud Puppy";
				total +=mud;
				round = mud;
				mudT++;
		    }
			
            if (die1.getValue() == 6) {
				fish = "Toilet Seat";
				total += toilet;
				round = toilet;								
				toiletT++;
		    }

		    std::cout << "\n";
		    std::cout << "\tThe die landed on " << die1.getValue() << " resulting in you catching a " << fish << std::endl;
		    std::cout << "\t            Your " << fish << " is worth " << round << " points\n";
		    std::cout << "\t               Your total score so far is "<< total << std::endl;
		    std::cout << "\n";
		    std::cout << "\t\t   Would you like to continue playing?\n";
		    std::cout << "\t\t   Please enter Y for YES or N for NO :";
		    std::cin >> choice;
        }
	}
    
	std::cout << "*******************************************************************************\n";
	std::cout << "*                        FISHING GAME SCORE TALLY                             *\n";
	std::cout << "*******************************************************************************\n";
	std::cout << "          You caught a HUGE FISH " << hugeT << " times equaling : " << (hugeT * 20) << " points\n" ;
	std::cout << "          You caught a Old Shoe " << oldT << " times equaling : " << (oldT * -7) << " points\n" ;
	std::cout << "          You caught a Tiny Fish " << tinyT << " times equaling : " << (tinyT * 5) << " points\n" ;
	std::cout << "          You caught a Normal Fish " << normalT << " times equaling : " << (normalT * 10) << " points\n" ;
	std::cout << "          You caught a Mud Puppy " << mudT << " times equaling : " << (mudT * -1) << " points\n" ;
	std::cout << "          You caught a Toilet Seat " << toiletT << " times equaling : " << (toiletT * -20) <<" points\n" ;
	std::cout << "*******************************************************************************\n";
	std::cout << "                     Your total score is :" << total << "\n";
	std::cout << "*******************************************************************************\n";
	std::cout << "*******************************************************************************\n";

	return 0;
}
#include <iostream>
#include <string>

int main() {
    std::string vegetarian,
           vegan,
           gluten_free;

    std::cout << "Is anyone in your party a vegetarian? ";
    std::cin >> vegetarian;

    if (vegetarian == "yes" || vegetarian == "no") {
        std::cout << "Is anyone in your party a vegan? ";
        std::cin >> vegan;

        if (vegan == "yes" || vegan == "no") {
            std::cout << "Is anyone in your party a gluten-free? ";
            std::cin >> gluten_free;

            if (gluten_free == "yes" || gluten_free == "no") {
                std::cout << "\nHere are your restaurant choices:"
                     <<  std::endl;

                if(vegetarian == "yes") {
                   if(vegan == "yes") {
                       if(gluten_free == "yes" ||
                          gluten_free == "no") {
                            std::cout << "   Corner Cafe\n";
                            std::cout << "   The Chef's Kitchen\n";
                       }                       
                   } else {
                        if(gluten_free == "yes") {
                            std::cout << "   Main Street Pizza Company\n";
                            std::cout << "   Corner Cafe\n";
                            std::cout << "   The Chef's Kitchen\n";
                        } else {
                            std::cout << "   Main Street Pizza Company\n";
                            std::cout << "   Corner Cafe\n";
                            std::cout << "   Mama's Fine Italian\n";
                            std::cout << "   The Chef's Kitchen\n";
                        }
                   }
                } else {
                    if (vegan == "yes") {
                        if (gluten_free == "yes" ||
                            gluten_free == "no") {
                            std::cout << "   Corner Cafe\n";
                            std::cout << "   The Chef's Kitchen\n";
                        }
                    } else {
                        if (gluten_free == "yes") {
                            std::cout << "   Main Street Pizza Company\n";
                            std::cout << "   Corner Cafe\n";
                            std::cout << "   The Chef's Kitchen\n";
                        } else {
                            std::cout << "   Joe's Gourmet Burgers\n";
                            std::cout << "   Main Street Pizza Company\n";
                            std::cout << "   Corner Cafe\n";
                            std::cout << "   Mama's Fine Italian\n";
                            std::cout << "   The Chef's Kitchen\n";
                        }   
                    }
                }   
            } else {
                std::cout << "\nError. \"yes\" or \"no\" must be chosen.\n"
                     << "Rerun the program and try again."
                     << std::endl;
            }
        } else {
            std::cout << "\nError. \"yes\" or \"no\" must be chosen.\n"
                     << "Rerun the program and try again."
                     << std::endl;
        }
    } else {
        std::cout << "\nError. \"yes\" or \"no\" must be chosen.\n"
                     << "Rerun the program and try again."
                     << std::endl;
    }

    return 0;
}
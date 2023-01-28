#include <iostream>
#include <string>

void validateInput(double &input);
double total_charges(double days, double rate, double charges, double meds_charges);
double total_charges(double charges, double meds_charges);

int main() {
    std::string patient_type = "";

    std::cout << "Inpatient or Outpatient? ";
    getline(std::cin, patient_type);
    
    if (patient_type == "inpatient" || patient_type == "Inpatient") {
        double days = 0.0;
        std::cout << "Days spent in the hospital: ";
        validateInput(days);

        double rate = 0.0;
        std::cout << "Daily rate: ";
        validateInput(rate);

        double charges = 0.0;
        std::cout << "Charges for hospital services: ";
        validateInput(charges);

        double meds_charges = 0.0;
        std::cout << "Charges for hospital medication: ";
        validateInput(meds_charges);

        double total = total_charges(days, rate, charges, meds_charges);

        std::cout << "Total charges: $" << total << std::endl;
    } else if (patient_type == "outpatient" || patient_type == "Outpatient") {
        double charges = 0.0;
        std::cout << "Charges for hospital services: ";
        validateInput(charges);

        double meds_charges = 0.0;
        std::cout << "Charges for hospital medication: ";
        validateInput(meds_charges);

        double total = total_charges(charges, meds_charges);

        std::cout << "Total charges: $" << total << std::endl;
    } else {
        std::cout << "Please enter a valid patient category" << std::endl;
    }
    
    return 0;
}

double total_charges(double days, double rate, double charges, double meds_charges) {
    return (days * rate + charges + meds_charges);
}

double total_charges(double charges, double meds_charges) {
    return (charges + meds_charges);
}

void validateInput(double &input) {
    do {
        std::cout << "Please enter an input greater or equal to zero." << std::endl;
        std::cin >> input;
    } while (input < 0);
}
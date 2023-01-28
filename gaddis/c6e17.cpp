#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

void validateInput(double &input);
double total_charges(double days, double rate, double charges, double meds_charges);
double total_charges(double charges, double meds_charges);

int main() {
    std::string patient_type = "";

    std::ofstream hospital_file;
    hospital_file.open("data/hospital.txt");

    
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

        if (hospital_file) {
            hospital_file << "Patient type: " << std::right << patient_type << "\n";
            hospital_file << "Days spent in the hospital: " << std::setw(29) << std::right << days << "\n";
            hospital_file << "Daily rate: " << std::setw(40) << std::right << "$" << std::fixed << std::setprecision(2) << rate << "\n";
            hospital_file << "Charges for hospital services: " << std::setw(20) << std::right << "$" << std::fixed << std::setprecision(2) << charges << "\n";
            hospital_file << "Charges for hospital medication: " << std::setw(18) << std::right << "$" << std::fixed << std::setprecision(2) << meds_charges << "\n";
            hospital_file << "Total charges: " << std::setw(36) << std::right << "$" << std::fixed << std::setprecision(2) << total;
        }
    } else if (patient_type == "outpatient" || patient_type == "Outpatient") {
        double charges = 0.0;
        std::cout << "Charges for hospital services: ";
        validateInput(charges);

        double meds_charges = 0.0;
        std::cout << "Charges for hospital medication: ";
        validateInput(meds_charges);

        double total = total_charges(charges, meds_charges);

        std::cout << "Total charges: $" << total << std::endl;

        if (hospital_file) {
            hospital_file << "Patient type: " << std::right << patient_type << "\n";
            hospital_file << "Charges for hospital services: " << std::setw(20) << std::right << "$" << std::fixed << std::setprecision(2) << charges << "\n";
            hospital_file << "Charges for hospital medication: " << std::setw(18) << std::right << "$" << std::fixed << std::setprecision(2) << meds_charges << "\n";
            hospital_file << "Total charges: " << std::setw(36) << std::right << "$" << std::fixed << std::setprecision(2) << total;
        }
    } else {
        std::cout << "Please enter a valid patient category." << std::endl;
    }

    hospital_file.close();
    
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
#include <iostream>

int main() {
    const int EVENING_TICKETS = 10;
    const int MATINEE_TICKETS = 3;
    const double EVENING_CONCESSIONS = 6.50F;
    const double MATINEE_CONCESSIONS = 8.50F;

    std::cout << "Number of evening tickets sold: ";
    int et_sold = 0;
    std::cin >> et_sold;

    std::cout << "Number of matinee tickets sold: ";
    int mt_sold = 0;
    std::cin >> mt_sold;

    double ticket_evening_income =  et_sold * EVENING_TICKETS;
    double ticket_matinee_income =  mt_sold * MATINEE_TICKETS;

    double concession_evening_income =  et_sold * EVENING_CONCESSIONS;
    double concession_matinee_income =  mt_sold * MATINEE_CONCESSIONS;

    double total_ticket_income = ticket_evening_income + ticket_matinee_income;
    double total_concession_income = concession_evening_income + concession_matinee_income;

    double total_income = total_ticket_income + total_concession_income;

    double evening_ticket_percentage = ticket_evening_income / total_income * 100;
    double matinee_ticket_percentage = ticket_matinee_income / total_income * 100;
    double cevening_ticket_percentage = concession_evening_income / total_income * 100;
    double cmatinee_ticket_percentage = concession_matinee_income / total_income * 100;

    std::cout << "Percentage of evening show income: " << evening_ticket_percentage << "%" << std::endl;
    std::cout << "Percentage of matinee show income: " << matinee_ticket_percentage << "%" << std::endl; 
    std::cout << "Percentage of evening concession income: " << cevening_ticket_percentage << "%" << std::endl; 
    std::cout << "Percentage of matinee concession income: " << cmatinee_ticket_percentage << "%" << std::endl; 
 
    return 0;
}
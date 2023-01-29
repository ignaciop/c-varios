#include "Heading.h"
#include <iostream>
#include <string>
#include <iomanip>

Heading::Heading(std::string cn, std::string rn) {
    company_name = cn;
    report_name = rn;
}

Heading::~Heading() {}

void Heading::printOneLiner() {
    std::cout << company_name << " " << report_name << std::endl;
}

void Heading::printFourLiner() {
    int total_length = company_name.length() + report_name.length();

    std::string stars = "";
    stars.assign(total_length * 2, '*');

    std::cout << stars << std::endl;

    int padding = total_length + (company_name.length() / 2);
    std::cout << std::setw(padding) << company_name << std::endl;

    padding = total_length + (report_name.length() / 2);
    std::cout << std::setw(padding) << report_name << std::endl;
    
    std::cout << stars << std::endl;
}
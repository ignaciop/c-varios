#include <iostream>
#include <string>

struct CorpData {
    std::string div_name;
    double qtr1_sales;
    double qtr2_sales;
    double qtr3_sales;
    double qtr4_sales;
};

CorpData newCorpData(std::string inputDivName, double inputQtr1Sales, double inputQtr2Sales, double inputQtr3Sales, double inputQtr4Sales);
void displayCorpData(const std::string &div_name, double &qtr1Sales, double &qtr2Sales, double &qtr3Sales, double &qtr4Sales);

int main() {
    CorpData north = newCorpData("North", 10, 20, 30, 40);
    CorpData south = newCorpData("South", 10.1, 20.1, 30.1, 40.1);
    CorpData east = newCorpData("East", 10.2, 20.2, 30.2, 40.2);
    CorpData west = newCorpData("West", 10.3, 20.3, 30.3, 40.3);

    displayCorpData(north.div_name, north.qtr1_sales, north.qtr2_sales, north.qtr3_sales, north.qtr4_sales);
    displayCorpData(south.div_name, south.qtr1_sales, south.qtr2_sales, south.qtr3_sales, south.qtr4_sales);
    displayCorpData(east.div_name, east.qtr1_sales, east.qtr2_sales, east.qtr3_sales, east.qtr4_sales);
    displayCorpData(west.div_name, west.qtr1_sales, west.qtr2_sales, west.qtr3_sales, west.qtr4_sales);

    return 0;
}

CorpData newCorpData(std::string inputDivName, double inputQtr1Sales, double inputQtr2Sales, double inputQtr3Sales, double inputQtr4Sales) {
    CorpData ncd = {inputDivName, inputQtr1Sales, inputQtr2Sales, inputQtr3Sales, inputQtr4Sales};

    return ncd;
}

void displayCorpData(const std::string &div_name, double &qtr1Sales, double &qtr2Sales, double &qtr3Sales, double &qtr4Sales) {
    std::cout << "\nDivision: " << div_name << std::endl;

    double annual_sales = qtr1Sales + qtr2Sales + qtr3Sales + qtr4Sales;
    double qtr_avg = annual_sales / 4;

    std::cout << "Total annual sales: $" << annual_sales << std::endl;
    std::cout << "Quarterly average: $" << qtr_avg << std::endl;
}
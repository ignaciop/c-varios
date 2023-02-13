#include <iostream>

using namespace std;

int main() {
    double original_price, percentage_mark, sales_tax;

    cout << "Enter the original price: ";
    cin >> original_price;

    cout << "Enter the percentage of the marked-up price: ";
    cin >> percentage_mark;

    cout << "Enter the sales tax rate: ";
    cin >> sales_tax;

    double selling_price = original_price + original_price * percentage_mark / 100;
    double sales_tax_price = selling_price * sales_tax / 100;
    double final_price = selling_price + sales_tax_price;

    cout << "Original price    : $" << original_price << endl;
    cout << "Mark-up percentage: " << percentage_mark << "%" << endl;
    cout << "Selling price     : $" << selling_price << endl;
    cout << "Sales tax rate    : " << sales_tax << "%" << endl;
    cout << "Sales tax         : $" << sales_tax_price << endl;
    cout << "Final price       : $" << final_price << endl;
    
    return 0;
}
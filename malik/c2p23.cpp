#include <iostream>

using namespace std;

int main() {
    const double SERVICE_CHARGE = 0.015;

    int shares;
    double purchase_price, selling_price, service_charges, invested, gain_loss, received;

    cout << "Enter the number of shares sold: ";
    cin >> shares;

    cout << "Enter the purchase price per share: ";
    cin >> purchase_price;

    cout << "Enter the selling price per share: ";
    cin >> selling_price;

    invested = shares * purchase_price;
    service_charges = invested * SERVICE_CHARGE;
    received = shares * selling_price - service_charges;
    gain_loss = received - invested;

    cout << "Amount invested    : $" << invested << endl;
    cout << "Service charges    : $" << service_charges << endl;
    cout << "Amount received    : $" << received << endl;
    cout << "Amount gain or lost: $" << gain_loss << endl;
    
    return 0;
}
#include "Tips.h"

double Tips::computeTip(double totalBill, double tipRate) {
    double bill_before_tax = totalBill - totalBill * taxRate;

    return (bill_before_tax * tipRate);
}
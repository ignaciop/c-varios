#ifndef TIPS_H
#define TIPS_H

class Tips {
    private:
        double taxRate;
    
    public:
        Tips(double inputTaxRate) : taxRate(inputTaxRate) {};
        Tips() : taxRate(0.085) {};
        ~Tips() {};

        double computeTip(double totalBill, double tipRate); 
};

#endif
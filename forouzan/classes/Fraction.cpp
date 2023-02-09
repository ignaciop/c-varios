#include "Fraction.h"
#include <iostream>
#include <cmath>
#include <cassert>

Fraction::Fraction(int num, int den = 1) : numer(num), denom(den) {
    normalize ();
}

Fraction::Fraction() : numer(0), denom(1) {}

Fraction::Fraction(const Fraction& fract) : numer(fract.numer), denom(fract.denom) {}

Fraction::~Fraction() {}

int Fraction::getNumer() const {
    return numer;
}

int Fraction::getDenom() const {
    return denom;
}

void Fraction::print() const {
    std::cout << numer << "/" << denom << std::endl;
}

void Fraction::setNumer(int num) {
    numer = num;
    
    normalize();
}

void Fraction::setDenom(int den) {
    denom = den;

    normalize();
}

void Fraction::normalize() {
    // Handling a denominator of zero
    if (denom == 0) {
        std::cout << "Invalid denomination. Need to quit." << std::endl;

        assert (false);
    }

    // Changing the sign of denominator
    if (denom < 0) {
        denom = -denom;
        numer = -numer;
    }

    // Dividing numerator and denominator by gcd
    int divisor = gcd(abs(numer), abs (denom));
    numer /= divisor;
    denom /= divisor;
}

int Fraction::gcd(int n, int m) {
    int gcd = 1;

    for (int k = 1; k <= n && k <= m; k++) {
        if (n % k == 0 && m % k == 0) {
            gcd = k;
        }
    }

    return gcd;
}
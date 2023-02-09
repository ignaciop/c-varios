#include "Number.h"
#include <iostream>

Number::Number() : value_(0) {}

void Number::setNumber(const std::string &num, unsigned int base) {
    if (validate(num, base)) {
        value_ = 0;
        
        for (char c : num) {
            value_ = value_ * base + toInt(c);
        }
    }
}

std::string Number::getNumber(unsigned int base) const {
    std::string result;
    unsigned int n = value_;
  
    while (n > 0) {
        result = pushFront(result, toChar(n % base));
        
        n /= base;
    }
  
    return result.empty() ? "0" : result;
}

unsigned int Number::toInt(char c) const {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
  
    return 0;
}

char Number::toChar(unsigned int i) const {
    if (i >= 0 && i <= 9) return '0' + i;
    if (i >= 10 && i <= 15) return 'A' + i - 10;
    
    return '0';
}

std::string Number::pushFront(const std::string &str, char c) const {
    return c + str;
}

std::string Number::popFront(const std::string &str) const {
    return str.substr(1);
}

bool Number::validate(const std::string &num, unsigned int base) const {
    for (char c : num) {
        if (toInt(c) >= base) return false;
    }
  
    return true;
}
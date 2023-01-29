#ifndef HEADING_H
#define HEADING_H

#include <string>

class Heading {
    private:
        std::string company_name;
        std::string report_name;
    
    public:
        Heading() : Heading("ABC Industries", "Report") {};
        Heading(std::string cn, std::string rn);
        ~Heading();

        void printOneLiner();
        void printFourLiner();
};

#endif
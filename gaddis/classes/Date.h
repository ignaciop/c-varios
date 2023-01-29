#ifndef DATE_H
#define DATE_H

class Date {
    private:
        int month;
        int day;
        int year;
    public:
        Date() : Date(1, 1, 2001) {}
        Date(int inputMonth, int inputDay, int inputYear);
        ~Date();

        void printShortDate();
        void printLongDate();
        void printLongDate2();
};

#endif
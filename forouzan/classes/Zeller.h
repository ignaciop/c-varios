#ifndef ZELLER_H
#define ZELLER_H

class Zeller {
    private:
        int day;
        int month;
        int year;

    public:
        Zeller();
        Zeller(int iDay, int iMonth, int iYear);
        Zeller(const Zeller& zellerCopy);
        ~Zeller();

        void weekday() const;
};

#endif
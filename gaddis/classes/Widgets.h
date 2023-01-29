#ifndef WIDGETS_H
#define WIDGETS_H

class Widgets {
    private:
        int widgets_per_hour;
        int work_hours_per_day;
    
    public:
        Widgets() : widgets_per_hour(10), work_hours_per_day(16) {}
        ~Widgets() {}

        void numOfDays(int order);
};

#endif
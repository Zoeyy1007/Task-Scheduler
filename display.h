#ifndef DISPLAY_HPP
#define DISPLAY_HPP
#include <iostream>
#include <string>
#include "Schedule.h"


using namespace std;
class Display {
    public: 
        Display();
        void display_category(Schedule sched);
        void display_priority(Schedule sched);
        void d_display_full(Schedule sched);
        void display_complete(Schedule sched);
        void display_day(Schedule sched);
        void single_display(Task* currtask);
        ~Display();
};
#endif 
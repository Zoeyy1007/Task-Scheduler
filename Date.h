#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <chrono>
#include <ctime>
#include <stdexcept>  

using namespace std;

class Date {
public:
    tm weekday{};
    
    Date(int month, int day);
    int day_in_week();
};

#endif

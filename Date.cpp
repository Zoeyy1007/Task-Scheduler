#include <iostream>
#include <chrono>
#include <ctime>
#include "Date.h"
using namespace std;

Date::Date(int month, int day) {
    // Validate input month and day
    if (month < 1 || month > 12) {
        throw runtime_error("Invalid month. Must be between 1 and 12.");
    }
    if (day < 1 || day > 31) {  
        throw runtime_error("Invalid day. Must be between 1 and 31.");
    }
    weekday = {};
    weekday.tm_year = 2025-1900;
    weekday.tm_mon = month-1; //0 is January
    weekday.tm_mday = day;
    weekday.tm_hour = 12;
    weekday.tm_min = 0;
    weekday.tm_sec = 0;
      
    time_t time = mktime(&weekday);
    if(time == -1){
      throw runtime_error("Invalid date. ");
    }
}

    int Date::day_in_week() {
        return weekday.tm_wday;
    }



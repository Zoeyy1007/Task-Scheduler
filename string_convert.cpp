#include <iostream>
#include <chrono>
#include <ctime>
#include "string_convert.h"
using namespace std;


    void Date_convert::convert_date_to_int(int& year, int& month, int&day){
        year = stoi(date.substr(0,4));
        month = stoi(date.substr(5,2));
        day = stoi(date.substr(8,2));
        
    }

    void time_convert::convert_time_int(int& hour, int&min){
        hour = stoi(time.substr(0,2));
        min = stoi(time.substr(3,5));
    }
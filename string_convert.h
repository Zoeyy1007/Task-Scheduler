#include <iostream>
#include <chrono>
#include <ctime>
#include <stdexcept>  

using namespace std;

class string_convert {
public:
    string time;
    void convert_to_int();
    
};

class Date_convert: public string_convert {
    public:
    string date;
    Date_convert(string date){this->date = date;}
    void convert_date_to_int(int& year, int& month, int&day);
};

class time_convert: public string_convert{
    public:
    string time;
    time_convert(string time){this->time = time;}
    void convert_time_int(int& hour, int&min);
};

#endif

#include <iostream>
#include <vector>

using namespace std;

class Time{
    private:
        int year;
        int month;
        int day;
        int CurrTime; //time in 24 hours
    public:
        Time(int y, int m, int d, int t){this->year= y; this->month=m; this->day = d; this->CurrTime=t;}
        Time();
};
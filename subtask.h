#ifndef SUBTASK_HPP
#define SUBTASK_HPP
#include <string>
#include <iostream>
#include <iostream>
#include "string_convert.h"
#include <vector>



using namespace std;


class Subtask {
        string name;
        string category;
        bool completion;
        int year;
        int month;
        int day;
        int hour;
        int min;
    public: 
        Subtask();
        //setters
        void set_completion_true();
        void set_completion_false();
        void set_name(string subname);
        void set_category(string catname);

        //getters
        bool get_completion();
        string get_name();
        string get_category();
        int get_year();
        int get_month();
        int get_day();
        int get_hour();
        int get_min();

        void input_subtask(int tYear, int tMonth, int tDay, int tHour, int tMin);
        void display_subtask();
};
#endif 
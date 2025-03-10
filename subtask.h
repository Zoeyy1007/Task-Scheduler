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
        bool get_completion()const;
        string get_name()const;
        string get_category()const;
        int get_year() const;
        int get_month() const;
        int get_day()const;
        int get_hour()const;
        int get_min()const;

        void input_subtask(int tYear, int tMonth, int tDay, int tHour, int tMin);
        void display_subtask() const;
};
#endif 
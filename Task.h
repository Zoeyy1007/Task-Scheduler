#include <iostream>
#include <vector>
#include "Date.cpp"

using namespace std;

class Task{
    private:
        int exec_time;
        string task_name;
        int priority;
        string category;
        int month;
        int day;
        int hour;
        int day_in_week;
        bool task_complete = false;
    
    public:
        void complete_task();
        bool get_status(){return task_complete;}
        int get_priority(){return priority;}
        int get_month() {return month;}
        int get_hour(){return hour;}
        int get_day(){return day;}
        string get_name(){return task_name;}
        string get_date();
        int get_day_in_week(){return day_in_week;}
        Task(string taskname, int priority, string category, int month, int day, int hour);
        Task();
        string get_category(){return category;}
        void Edit_name();

        void set_name(string newName);    
        void set_month(int month);
        void set_priority(int newPriority);
        void set_category(string newCategory);
        void set_day(int newDay);
        void set_hour(int newHour);
};


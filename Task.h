#ifndef TASK_H
#define TASK_H
#include <iostream>
#include <vector>

using namespace std;

class Task{
    private:
        int exec_time;
        string task_name;
        int priority;
        string task_date;
        string category;
        int day;
        int hour;
        int week;
        bool task_complete = false;
    
    public:
        void complete_task();
        bool get_status();
        int get_priority();
        int get_hour();
        int get_day();
        string get_name();
        string get_date();
        Task(string taskname, string task_date, int priority, string category, int day, int hour, int week);
        Task();
        string get_category();
       
        //setter
        void set_name(string newName);    
        void set_date(string newDate);
        void set_priority(int newPriority);
        void set_category(string newCategory);
        void set_day(int newDay);
        void set_hour(int newHour);

};
#endif // TASK_H
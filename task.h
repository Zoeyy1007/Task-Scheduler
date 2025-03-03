#ifndef TASK_HPP
#define TASK_HPP
#include <iostream>
using namespace std;

class Task {
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

    Task(string taskname, string task_date, int priority, string category, int day, int hour)
    
    //getters
    bool get_status();
    string getName();
    int getPriority();
    string getDate();
    int get_exec_time();
    int get_day();
    int get_hour();
    string get_category();

    //setter
    void set_name(string newName);    
    void set_date(string newDate);
    void set_priority(int newPriority);
    void set_category(string newCategory);
    void set_day(int newDay);
    void set_hour(int newHour);

    //completion
    void complete_task();
};



#endif // TASK_HPP
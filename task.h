#ifndef TASK_HPP
#define TASK_HPP
#include <iostream>
using namespace std;

class Task {
    private:
    string task_name;
    int task_priority = 0;
    string task_date;
    int task_exec_time = 0;
    int task_day;
    int task_hour;
    int task_complete;

    public:

    Task(string taskname, string task_date, int priority, string category, int day, int hour)
    
    //getters
    bool get_status();
    string getName();
    int getPriority();
    string getDate();
    int get_exec_time();
    int get_day()
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
    void task_complete();
};



#endif // TASK_HPP
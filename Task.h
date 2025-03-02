
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
        int get_week();
        string get_name();
        string get_date();
        Task(string taskname, string task_date, int priority, string category, int day, int hour);
        Task();
        string get_category();
       
};


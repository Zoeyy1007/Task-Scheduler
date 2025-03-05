
#include <iostream>
#include <vector>

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

        bool task_complete = false;
    
    public:
        void complete_task();
        bool get_status();
        int get_priority();

        int get_hour();
        int get_day();
        string get_name();
        string get_date();
        Task(string taskname, int priority, string category, int month, int day, int hour);
        Task();
        string get_category();
        void Edit_name();
};


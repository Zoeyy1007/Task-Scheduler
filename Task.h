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
    
    public:
        void complete_task();
        bool task_complete = false;
        int get_priority();
        string get_name();
        string get_date();
        Task(string taskname, string taskDate,  int priority, string category);
        Task();
        string get_category();
};
#ifndef TASK_HPP
#define TASK_HPP
#include <iostream>
using namespace std;

class Task {
    private:
    string task_name;
    int task_priority = 0;
    int task_date = 0;
    int task_exec_time = 0;
    public:
    bool task_complete = 0;
    string getName();
    int getPriority();
    int getDate();
    int get_exec_time();
};



#endif // TASK_HPP
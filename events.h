#ifndef EVENT_HPP
#define EVENT_HPP
#include <iostream>
using namespace std;

class Event {
    private:
    string event_name;
    int event_priority = 0;
    int event_date = 0;
    int event_exec_time = 0;
    public:
    bool task_complete = 0;
    string getName();
    int getPriority();
    int getDate();
    int get_exec_time();
};



#endif // EVENT_HPP
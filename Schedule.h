#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <iostream>
#include <vector>
#include "Task.h"

using namespace std;

class Schedule {
private:
    string schedule_name;
    int size = 0;
    vector<Task*> the_Tasks;

public:
    Schedule();  
    Schedule(string schedule_name);  
    ~Schedule();  // ✅ Explicitly declare the destructor

    void add_task();  
    void add_task(string taskname, string taskdate, int priority, string category);
    
    void remove_task(int num);  
    int get_size();
    
    int get_priority();  
    int get_execTime();  
    
    void display_categorized();  
    void display_full();  
    bool is_active();  
    
    void display_by_category();  
    void complete_task(int index);  

    Task* get_task(int index);  
};

#endif // SCHEDULE_H

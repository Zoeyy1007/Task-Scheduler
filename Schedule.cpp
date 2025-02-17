#include <iostream>
#include <vector>
#include "Schedule.h"
#include "Task.h"

using namespace std;

void Schedule::add_task(string taskname, string taskDate,  int priority){
    Task* taskPtr = new Task(taskname, taskDate, priority);
    the_Tasks.push_back(taskPtr);
    size++;
}

void Schedule::remove_task(int num){
    if(num <=0){
        cout << "Invalid input" << endl;
        return;
    }
    num = num-1;
    Task* curr_task = the_Tasks.at(num);
    the_Tasks.erase(the_Tasks.begin()+num);
    delete curr_task;
    return;
}
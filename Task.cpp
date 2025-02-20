#include <iostream>
#include <vector>
#include "Task.h"

using namespace std;

Task::Task(string taskname, string taskDate,  int priority){
    this->task_name=taskname;
    this->task_date=taskDate;
    this->priority=priority;
}

void Task::complete_task(){
    if(task_complete == true){return;}
    task_complete = true;
}

string Task::get_date(){
    return task_date;
}

string Task::get_name(){
    return task_name;
}

int Task::get_priority(){
    return priority;
}
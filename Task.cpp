#include <iostream>
#include <vector>
#include "Task.h"

using namespace std;


Task::Task(string taskname, int priority, string category, int month, int day, int hour){
    
    this->task_name=taskname;
    this->priority=priority;
    this->category = category;
    this->month = month;
    this->day = day;
    this->hour = hour;

}

void Task::complete_task(){
    if(task_complete == true){return;}
    task_complete = true;
}


string Task::get_date(){
    string date = to_string(month) + "/" + to_string(day);
    return date;
}

string Task::get_name(){
    return task_name;
}

int Task::get_priority(){
    return priority;
}


int Task::get_hour(){
    return hour;
}

int Task::get_day(){
    return day;
}


string Task::get_category(){
    return category;
}

bool Task::get_status(){
    return task_complete;
}

void Task::Edit_name(){
    string new_name = " ";
    cout << "Please enter the new name for current task." << endl;
    cin.ignore();
    getline(cin, new_name);
    task_name = new_name;
    cout << "You changed the task name to " << task_name << endl;
}
#include <iostream>
#include <vector>
#include "Task.h"

using namespace std;

Task::Task(string taskname, string task_date, int priority, string category, int day, int hour){
    
    this->task_name=taskname;
    this->priority=priority;
    this->task_date = task_date;
    this->category = category;
    this->day = day;
    this->hour = hour;
    this->task_complete = false;
}

void Task::complete_task(){
    if(!task_complete)
        return task_complete = true;
}

//getter
string Task::get_date(){
    return task_date;
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

//setter
void Task::set_name(string newName){
    task_name = newName;
}

void Task::set_date(string newDate){
    task_date = newDate;
}

void Task::set_priority(int newPriority){
    priority = newPriority;
}

void Task::set_category(string newCategory){
    category = newCategory;
}

void Task::set_day(int newDay){
    day = newDay;
}

void Task::set_hour(int newHour){
    hour = newHour;
}

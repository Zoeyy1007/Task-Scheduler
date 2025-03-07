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
    Date the_date = Date(month, day);
    this->day_in_week = the_date.day_in_week();
}

void Task::complete_task(){
    if(task_complete == true){return;}
    task_complete = true;
}


string Task::get_date(){
    string date = to_string(month) + "/" + to_string(day);
    return date;
}


void Task::set_name(string newName) {  
    task_name = newName;
}

void Task::set_month(int month) {
    this->month = month;
}

void Task::set_priority(int newPriority) {
    priority = newPriority;
}

void Task::set_category(string newCategory) {
    category = newCategory;
}

void Task::set_day(int newDay) {
    day = newDay;
}

void Task::set_hour(int newHour) {
    hour = newHour;
}
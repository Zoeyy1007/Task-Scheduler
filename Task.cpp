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
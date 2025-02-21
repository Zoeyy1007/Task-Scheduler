#include <iostream>
#include <vector>
#include "Schedule.h"

using namespace std;

void Schedule::add_task(string taskname, string taskDate,  int priority){
    Task* taskPtr = new Task(taskname, taskDate, priority);
    the_Tasks.push_back(taskPtr);
    size++;
}

void Schedule::remove_task(int num){//input the task number of it in the vector
    if(num <=0){
        cout << "Invalid input" << endl;
        return;
    }
    num = num-1;
    Task* curr_task = the_Tasks.at(num);
    the_Tasks.erase(the_Tasks.begin()+num);
    delete curr_task;
    size--;
    return;
}

void Schedule::display_full(){
    if(the_Tasks.size() == 0){return;}
    for (int i = 0; i < size; i++){
        cout << i + 1 << ", " ;
        cout << the_Tasks.at(i)->get_name() << ", at " << the_Tasks.at(i)->get_date();
        cout << ", priority: " << the_Tasks.at(i)->get_priority() << endl;
    }
}

Schedule::Schedule(string schedule_name){
    this->schedule_name = schedule_name;
}

Schedule::Schedule(){
    schedule_name = '0';
}
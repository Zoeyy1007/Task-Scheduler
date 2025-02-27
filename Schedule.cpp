
#include <iostream>
#include <vector>
#include "Schedule.h"

using namespace std;

void Schedule::add_task(){
    string taskname;
    string taskDate;
    int priority;
    string category;
    cout << "Please enter event title" << endl;
    cin.ignore(); //ignore the /n from last input
    getline(cin, taskname);
    cout << "Please enter event time" << endl;
    cin.ignore(); 
    getline(cin, taskDate);
    cout << taskDate << endl;
    cout << "What is the priority of your event" << endl;
    cin >> priority;
    cout << priority << endl;
    cout << "What type of task it is?" << endl;
    cin.ignore();
    getline(cin, category);
    Task* taskPtr = new Task(taskname, taskDate, priority, category);
    the_Tasks.push_back(taskPtr);
    size++;
}

void Schedule::add_task(string taskname, string taskdate, int priority, string category){
    Task* taskPtr = new Task(taskname, taskdate, priority, category);
    the_Tasks.push_back(taskPtr);
    size++;
}


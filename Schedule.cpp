
#include <iostream>
#include <vector>
#include "Schedule.h"

using namespace std;

Schedule::Schedule() {}  // Default constructor

Schedule::Schedule(string schedule_name) : schedule_name(schedule_name) {} // Constructor with name

Schedule::~Schedule() {
    for (Task* task : the_Tasks) {  // ✅ FIXED: Using the_Tasks instead of tasks
        delete task;
    }
    the_Tasks.clear();
}

void Schedule::add_task() {
    string title, date, category;
    int priority;
    string category;

    cout << "Please enter event title" << endl;
    cin.ignore(); 
    
    getline(cin, taskname);
    cout << "Please enter event date" << endl;
    cin.ignore(); 

    getline(cin, taskDate);
    cout << taskDate << endl;

    cout << "Please enter task priority (1 to 5): ";
    cin >> priority; 
    while (priority < 1 || priority > 5) {
        cout << "Invalid priority. Please enter a value between 1 and 5: ";
        cin >> priority;
    }
    cin.ignore();
    cout << priority << endl;
    cout << "What type of task it is?" << endl;
    cin.ignore();
    getline(cin, category);

    Task* taskPtr = new Task(title, date, priority, category);
    the_Tasks.push_back(taskPtr);  // ✅ FIXED: Using the_Tasks instead of tasks
    size++;  
}

void Schedule::add_task(string taskname, string taskDate, int priority, string category) {  
    if (priority < 1) priority = 1;
    if (priority > 5) priority = 5;

    Task* taskPtr = new Task(taskname, taskDate, priority, category);
    the_Tasks.push_back(taskPtr);  // ✅ FIXED: Using the_Tasks instead of tasks
    size++;  
}

Task* Schedule::get_task(int index) {
    if (index >= 0 && index < the_Tasks.size()) {  // ✅ FIXED: Using the_Tasks instead of tasks
        return the_Tasks[index];
    }
    return nullptr;
}

int Schedule::get_size() {
    return the_Tasks.size();  // ✅ FIXED: Using the_Tasks instead of tasks
}

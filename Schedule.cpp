#include <iostream>
#include <vector>
#include "Schedule.h"

using namespace std;

void Schedule::add_task() {
    string title;
    string date;
    int priority;
    string category; 

    cout << "Please enter task title: " << endl;
    cin.ignore();
    getline(cin, title);

    cout << "Please enter task date: " << endl;
    getline(cin, date); 

    cout << "Please enter task priority(1 to 5): " << endl;
    cin >> priority; 
    cin.ignore();

    cout << "Please enter task category: " << endl;
    getline(cin, category);

    Task* taskPtr = new Task(title, date, priority, category); // Task object instantiation
    the_Tasks.push_back(taskPtr);
    size++;
}

void Schedule::add_task(string taskname, string taskDate, int priority) {
    Task* taskPtr = new Task(taskname, taskDate, priority);
    the_Tasks.push_back(taskPtr);
    size++;
}
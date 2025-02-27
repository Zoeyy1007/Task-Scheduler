
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
    cin.ignore();
    getline(cin, taskname);

    cout << "Please enter event time" << endl;
    cin.ignore(); 
    getline(cin, taskDate);
    cout << taskDate << endl;

    cout << "Enter priority (1 to 5): ";
    while (!(cin >> priority) || priority < 1 || priority > 5) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid priority. Please enter a number between 1 and 5: ";
    }
    cin.ignore();
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

Schedule::~Schedule() {
    for (Task* task : the_Tasks) {
        delete task; // Free memory
    }
}

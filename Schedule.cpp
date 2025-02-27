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
    if(the_Tasks.size() == 0){
        cout << "You don't have any task. " << endl;
        return;}
    for (int i = 0; i < size; i++){
        cout << i + 1 << ", " ;
        cout << the_Tasks.at(i)->get_name() << ", at " << the_Tasks.at(i)->get_date();
        cout << ", priority: " << the_Tasks.at(i)->get_priority();
        cout << ", category: " << the_Tasks.at(i)->get_category() << endl;
    }
}

Schedule::Schedule(string schedule_name){
    this->schedule_name = schedule_name;
}

Schedule::Schedule(){
    schedule_name = '0';
}

void Schedule::display_by_category(){
    if(the_Tasks.size() == 0){
        cout << "You don't have any task. " << endl;
    return;}
    string category = "School work";
    cout << "Category: " << category << endl;
    for (int i = 0; i < size; i++){
        if(the_Tasks.at(i)->get_category() == category){
            cout << the_Tasks.at(i)->get_name() << ", at " << the_Tasks.at(i)->get_date();
            cout << ", priority: " << the_Tasks.at(i)->get_priority() << endl;
        }
    }
    category = "home";
    cout << "Category: " << category << endl;
    for (int i = 0; i < size; i++){
        if(the_Tasks.at(i)->get_category() == category){
            cout << the_Tasks.at(i)->get_name() << ", at " << the_Tasks.at(i)->get_date();
            cout << ", priority: " << the_Tasks.at(i)->get_priority() << endl;
        }
    }
}

void Schedule::complete_task(int index){
    if(index <= 0){
        cout << "Invalid input" << endl;
        return;
    }
    Task* curr_task = the_Tasks.at(index-1);
    curr_task->complete_task();
    return;
}
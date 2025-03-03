#include <iostream>
#include <vector>
#include <stdexcept>
#include "Schedule.h"
#include "category.h"

using namespace std;

//constructor
Schedule::Schedule(){
    schedule_name = "Defult Schedule";
    size = 0;
}

Schedule::Schedule(string schedule_name){
    this->schedule_name = schedule_name;
    size = 0;
}

//add new task 
void Schedule::add_task(){
    string taskname;
    string taskDate;
    int priority;
    string category;
    int day;
    int hour;
    int week =0;


    cout << "Please enter event title" << endl; 
    getline(cin, taskname);

    cout << "Please enter event time" << endl;
    cin.ignore(); 
    getline(cin, taskDate);

    cout << "Please enter day, Monday is 1, Tuesday is 2, etc.." << endl;
    cin.ignore(); 
    cin >> day;

    cout << "Please enter hour of day, from 0 to 23" << endl;
    cin >> hour;

    cout << taskDate << endl;
    cout << "What is the priority of your event, 1 through 10 (10 being the most urgent)" << endl;
    cin >> priority;

    cout << "What category of task it is?" << endl;
    cin.ignore();
    getline(cin, category);

    Task* taskPtr = new Task(taskname, taskDate, priority, category, hour, day, week);
    the_Tasks.push_back(taskPtr);
    size++;
}

void Schedule::add_task(string taskname, string taskDate, int priority, string category, int hour, int day, int week){
    Task* taskPtr = new Task(taskname, taskDate, priority, category, hour, day, week);
    the_Tasks.push_back(taskPtr);
    size++;
}

//find task by name
Task* Schedule::findTask(string name){
    for (int i = 0; i < the_Tasks.size(); i++){
        if(the_Tasks[i]->get_name() == name){
            return the_Tasks[i];
        }
    }
    cout << "Task cannot be found" << endl;
    return nullptr;

}

//remove task by name
void Schedule::remove_task(string name){
    for(int i = 0; i < the_Tasks.size(); i++){
        if(name == the_Tasks[i]->get_name()){
            delete the_Tasks[i];
            the_Tasks.erase(the_Tasks.begin()+i);
            size--;
            return;
        }
    }
    cout << "No task by this name" << endl;
    return;
}

//Display functions
void Schedule::display_full(){
    if(the_Tasks.size() == 0){
        throw runtime_error("No tasks in schedule");
        return;
    }
    string daysOfWeek[7] = {"Monday:", "Tuesday:", "Wednesday:", "Thursday:", "Friday:", "Saturday:", "Sunday:"};


    vector<Task*> Monday;
    vector<Task*> Tuesday;
    vector<Task*> Wednesday;
    vector<Task*> Thursday;
    vector<Task*> Friday;
    vector<Task*> Saturday;
    vector<Task*> Sunday;
    for(int i = 0; i < the_Tasks.size(); i++){
       if(the_Tasks[i]->get_day()==1){
        Monday.push_back(the_Tasks[i]);
       }
       if(the_Tasks[i]->get_day()==2){
        Tuesday.push_back(the_Tasks[i]);
       }
       if(the_Tasks[i]->get_day()==3){
        Wednesday.push_back(the_Tasks[i]);;
       }
       if(the_Tasks[i]->get_day()==4){
        Thursday.push_back(the_Tasks[i]);;
       }
       if(the_Tasks[i]->get_day()==5){
        Friday.push_back(the_Tasks[i]);;
       }
       if(the_Tasks[i]->get_day()==6){
        Saturday.push_back(the_Tasks[i]);;
       }
       if(the_Tasks[i]->get_day()==7){
        Sunday.push_back(the_Tasks[i]);
       }
    }

    cout << "Monday:" << endl;
    int count = 1;
    for(int i = 0; i < Monday.size(); i++){
        cout << count << ":" << endl;
        single_display(Monday[i]);
        count++;
    }

     cout << "Tuesday:" << endl;
    count = 1;
    for(int i = 0; i < Tuesday.size(); i++){
        cout << count << ":" << endl;
        single_display(Tuesday[i]);
        count++;
    }
    cout << "Wednesday:" << endl;
    count = 1;
    for(int i = 0; i < Wednesday.size(); i++){
        cout << count << ":" << endl;
        single_display(Wednesday[i]);
        count++;
    }

     cout << "Thursday:" << endl;
     count = 1;
    for(int i = 0; i < Thursday.size(); i++){
        cout << count << ":" << endl;
        single_display(Thursday[i]);
        count++;
    }

     cout << "Friday:" << endl;
     count = 1;
    for(int i = 0; i < Friday.size(); i++){
        cout << count << ":" << endl;
        single_display(Friday[i]);
        count++;
    }
    cout << "Saturday:" << endl;
     count = 1;
    for(int i = 0; i < Saturday.size(); i++){
        cout << count << ":" << endl;
        single_display(Saturday[i]);
        count++;
    }

     cout << "Sunday:" << endl;
     count = 1;
    for(int i = 0; i < Sunday.size(); i++){
        cout << count << ":" << endl;
        single_display(Sunday[i]);
        count++;
    }
    
    
}

void Schedule::single_display(Task* currtask){
    cout << currtask->get_name() << ", at " << currtask->get_date();
    cout << ", priority: " << currtask->get_priority() << endl;
    cout << "Completion Status: ";
    cout << currtask->get_status();
}


void Schedule::display_by_priority(){
    cout << "Pick a priority to display (1 through 10)" << endl << endl;
    int prio;
    cin >> prio;
    cout << "DISPLAYING PRIORITY :" << prio << endl;
    int count = 1;
    for(int i = 0; i < the_Tasks.size(); i++){
        if(the_Tasks[i]->get_priority() == prio){
            cout << count << "." << endl;
            single_display(the_Tasks[i]);
            count++;
        }
    }
    return;
    
    
}

void Schedule::display_by_category(){
    if(the_Tasks.size() == 0){
        cout << "You don't have any task. " << endl;

    return;
    }
    int count = 1;
    string category;
    cin >> category;
    cout << "Category: " << category << endl;
    for (int i = 0; i < the_Tasks.size(); i++){
        if(the_Tasks.at(i)->get_category() == category){
            cout << count << "." << endl;

            cout << the_Tasks.at(i)->get_name() << ", at " << the_Tasks.at(i)->get_date();
            cout << ", priority: " << the_Tasks.at(i)->get_priority() << endl;
            cout << "Completion Status: " << the_Tasks.at(i)->get_status() << endl;
            count ++;
        }
    }
}


//mark as complete task
void Schedule::complete_task(string name){
    for(int i = 0; i < the_Tasks.size(); i++){
        if(the_Tasks[i]->get_name() == name){
            the_Tasks[i]->complete_task();
            return;
        }
    }
    cout << "Task not found";
    return;
}
//check if the task is completed 
bool Schedule::is_complete(string name){
    for(int i = 0; i < the_Tasks.size(); i++){
        if(the_Tasks[i]->get_name() == name){
            bool correct = the_Tasks[i]->get_status();
            if(correct == true){
                cout << "Is completed";
                return true;;
            }
            else{
                cout << "Is not completed";
                return false;
            }
        }
    }
    cout << "Task not found";
    return false;
}

//edit a task
void Schedule::edit_task(string name) {
    Task* task = findTask(name);

    if (task == nullptr) {
        cout << "Task not found. Unable to edit." << endl;
        return;
    }

    while (true) {
        string taskName = task->get_name();
        cout << "\nEditing Task: " << taskName << endl;
        cout << "1. Edit Name\n2. Edit Date\n3. Edit Priority\n4. Edit Category\n5. Edit Day\n6. Edit Hour\n7. Exit Edit Menu\n";
        cout << "Enter your choice: ";
        
        int choice;
        cin >> choice;
        cin.ignore(); 

        if (choice == 1) {
            string newName;
            cout << "Enter new task name: ";
            getline(cin, newName);
            task->set_name(newName);
        } 
        else if (choice == 2) {
            string newDate;
            cout << "Enter new date: ";
            getline(cin, newDate);
            task->set_date(newDate);
        } 
        else if (choice == 3) {
            int newPriority;
            cout << "Enter new priority (1-10): ";
            cin >> newPriority;
            while (newPriority < 1 || newPriority > 10) {
                cout << "Invalid priority. Enter a number between 1-10: ";
                cin >> newPriority;
            }
            task->set_priority(newPriority);
        } 
        else if (choice == 4) {
            string newCategory;
            cout << "Enter new category: ";
            getline(cin, newCategory);
            task->set_category(newCategory);
        } 
        else if (choice == 5) {
            int newDay;
            cout << "Enter new day (1 for Monday, 7 for Sunday): ";
            cin >> newDay;
            while (newDay < 1 || newDay > 7) {
                cout << "Invalid day. Enter a number between 1-7: ";
                cin >> newDay;
            }
            task->set_day(newDay);
        } 
        else if (choice == 6) {
            int newHour;
            cout << "Enter new hour (0-23): ";
            cin >> newHour;
            while (newHour < 0 || newHour > 23) {
                cout << "Invalid hour. Enter a number between 0-23: ";
                cin >> newHour;
            }
            task->set_hour(newHour);
        } 
        else if (choice == 7) {
            cout << "Exiting edit menu." << endl;
            return;
        } 
        else {
            cout << "Invalid choice, try again." << endl;
        }
    }
}
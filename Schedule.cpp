#include <iostream>
#include <vector>
#include <stdexcept>
#include "Schedule.h"
#include "category.h"


using namespace std;

//constructor
Schedule::Schedule(){
}

//add new task 
void Schedule::add_task(){
    string taskname;
    int priority;
    string category;
    int month;
    int day;
    int hour;

    cout << "Please enter event title" << endl; 
    cin.ignore();
    getline(cin, taskname);

    cout << "Please enter month, Janurary is 01, so on." << endl;
    cin >> month;

    cout << "Please enter the day, Januray 1st is 01, and so on" << endl;
    cin >> day;

    cout << "Please enter hour of day, from 0 to 23" << endl;
    cin >> hour;

  
    cout << "What is the priority of your event, 1 through 10 (10 being the most urgent)" << endl;
    cin >> priority;
    while(priority > 10 || priority < 0){
        cout << "Pick a priority that is within the range" << endl;
        cin >> priority;
    }

    cout << "What category of task it is?" << endl;
    cin.ignore();
    getline(cin, category);

    Task* taskPtr = new Task(taskname, priority, category, month,day, hour);

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

void Schedule::add_task(string taskname, int priority, string category, int month, int day, int hour){
    Task* taskPtr = new Task(taskname, priority, category, month, day, hour);


    the_Tasks.push_back(taskPtr);
    size++;
}


void Schedule::remove_task(string name){
    for(int i = 0; i < the_Tasks.size(); i++){
        if(name == the_Tasks[i]->get_name()){
            Task* temp = the_Tasks[i];
            the_Tasks.erase(the_Tasks.begin()+i);
            delete temp;
            size--;
            cout << name << "was deleted. " << endl;

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


    vector<Task*> Monday;
    vector<Task*> Tuesday;
    vector<Task*> Wednesday;
    vector<Task*> Thursday;
    vector<Task*> Friday;
    vector<Task*> Saturday;
    vector<Task*> Sunday;

    for(int i = 0; i < the_Tasks.size(); i++){
       if(the_Tasks[i]->get_day_in_week()==1){
        Monday.push_back(the_Tasks[i]);
       }
       if(the_Tasks[i]->get_day_in_week()==2){
        Tuesday.push_back(the_Tasks[i]);
       }
       if(the_Tasks[i]->get_day_in_week()==3){
        Wednesday.push_back(the_Tasks[i]);
       }
       if(the_Tasks[i]->get_day_in_week()==4){
        Thursday.push_back(the_Tasks[i]);
       }
       if(the_Tasks[i]->get_day_in_week()==5){
        Friday.push_back(the_Tasks[i]);
       }
       if(the_Tasks[i]->get_day_in_week()==6){
        Saturday.push_back(the_Tasks[i]);
       }
       if(the_Tasks[i]->get_day_in_week()==0){
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

    cout << endl;

     cout << "Tuesday:" << endl;
    count = 1;
    for(int i = 0; i < Tuesday.size(); i++){
        cout << count << ":" << endl;
        single_display(Tuesday[i]);
        count++;
    }

    cout << endl;

    cout << "Wednesday:" << endl;
    count = 1;
    for(int i = 0; i < Wednesday.size(); i++){
        cout << count << ":" << endl;
        single_display(Wednesday[i]);
        count++;
    }

    cout << endl;

     cout << "Thursday:" << endl;
     count = 1;
    for(int i = 0; i < Thursday.size(); i++){
        cout << count << ":" << endl;
        single_display(Thursday[i]);
        count++;
    }

    cout << endl;

     cout << "Friday:" << endl;
     count = 1;
    for(int i = 0; i < Friday.size(); i++){
        cout << count << ":" << endl;
        single_display(Friday[i]);
        count++;
    }

    cout << endl;


    cout << "Saturday:" << endl;
     count = 1;
    for(int i = 0; i < Saturday.size(); i++){
        cout << count << ":" << endl;
        single_display(Saturday[i]);
        count++;
    }

    cout << endl;

     cout << "Sunday:" << endl;
     count = 1;
    for(int i = 0; i < Sunday.size(); i++){
        cout << count << ":" << endl;
        single_display(Sunday[i]);
        count++;
    }
    cout << endl;
    
    
}

void Schedule::single_display(Task* currtask){
    cout << currtask->get_name() << ", at " << currtask->get_date();
    cout << ", priority: " << currtask->get_priority() << endl;
    cout << "Completion Status: ";
    cout << currtask->get_status() << endl;
}


void Schedule::display_by_priority(){
    cout << "Pick a priority to display (1 through 10)" << endl << endl;
    int prio;
    cin >> prio;
    cout << "DISPLAYING PRIORITY :" << prio << endl;
    int count = 1;
    for(int i = 0; i < the_Tasks.size(); i++){
        if(the_Tasks[i]->get_priority() == prio){
            cout << count << ".";
            single_display(the_Tasks[i]);
            count++;
        }
    }
    return;
    
    
}


void Schedule::display_by_day(){
    cout << "Please enter day, Monday is 1, Tuesday is 2, etc.." << endl << endl;
    int day;
    cin >> day;
    string days_of_week[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    cout << "DISPLAYING DAY :" << days_of_week[day] << endl;
    int count = 1;
    for(int i = 0; i < the_Tasks.size(); i++){
        if(the_Tasks[i]->get_day_in_week() == day){
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
    cout << "Enter a category name" << endl;
    cin >> category;
    cout << "Category: " << category << endl;
    for (int i = 0; i < size; i++){
        if(the_Tasks.at(i)->get_category() == category){
            cout << count << "." ;
            cout << the_Tasks.at(i)->get_name() << ", at " << the_Tasks.at(i)->get_date();
            cout << ", at " << the_Tasks.at(i)->get_hour();
            cout << ", priority: " << the_Tasks.at(i)->get_priority() << endl;
            cout << "Completion Status: " << the_Tasks.at(i)->get_status() << endl;
            count ++;
        }
    }
}


void Schedule::complete_task(const string& name){
    for(int i = 0; i < the_Tasks.size(); i++){
        if(the_Tasks[i]->get_name() == name){
            Task* task = the_Tasks[i];
            task->complete_task();
            //completed_Tasks.push_back(task);
            //the_Tasks.erase(the_Tasks.begin()+i);
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

Schedule::~Schedule(){
    Task* temp = nullptr;
    for(int i = 0; i < size; i++){
        temp = the_Tasks[i];
        delete temp;
    }
    size = 0;
}

void Schedule::edit_task(string name) {
    Task* task = findTask(name);

    if (task == nullptr) {
        cout << "Task not found. Unable to edit." << endl;
        return;
    }

    while (true) {
        string taskName = task->get_name();
        cout << "\nEditing Task: " << taskName << endl;
        cout << "1. Edit Name\n2. Edit Date\n3. Edit Priority\n4. Edit Category\n5. Edit Day\n6. Edit Hour\n7. Exit Edit Menu\n8. Mark an event as complete\n";
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
            int month;
            cout << "Enter new month: ";
            cin >> month;
            task->set_month(month);
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
        else if(choice == 8){
            complete_task(taskName);
        }
        else {
            cout << "Invalid choice, try again." << endl;
            cin >> choice;
        }
    }
}

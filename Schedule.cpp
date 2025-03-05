
#include <iostream>
#include <vector>
#include <stdexcept>
#include "Schedule.h"
#include "category.h"


using namespace std;

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

    cout << "Please enter hour of day, from 0 to 24" << endl;
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

    Task* taskPtr = new Task(taskname, priority, category, month, hour, day);

    the_Tasks.push_back(taskPtr);
    size++;
}


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
            return;
        }
    }
    cout << "No task by this name" << endl;
    return;
}



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
    string days_of_week[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    cout << "DISPLAYING DAY :" << days_of_week[day-1] << endl;
    int count = 1;
    for(int i = 0; i < the_Tasks.size(); i++){
        if(the_Tasks[i]->get_day() == day){
            cout << count << "." << endl;
            single_display(the_Tasks[i]);
            count++;
        }
    }
    return;
}

Schedule::Schedule(){
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
            cout << ", priority: " << the_Tasks.at(i)->get_priority() << endl;
            cout << "Completion Status: " << the_Tasks.at(i)->get_status() << endl;
            count ++;
        }
    }
}

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
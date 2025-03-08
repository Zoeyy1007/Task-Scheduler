#include <iostream>
#include <vector>
#include "display.h"

#include "Task.h"

using namespace std;


Display::Display(){

}

void Display::display_priority(Schedule sched){
    cout << "Pick a priority to display (1 through 10)" << endl << endl;
    int prio;
    cin >> prio;
    cout << "DISPLAYING PRIORITY :" << prio << endl;
    int count = 1;
    for(int i = 0; i < sched.the_Tasks.size(); i++){
        if(sched.the_Tasks[i]->get_priority() == prio){
            cout << count << ".";
            single_display(sched.the_Tasks[i]);
            count++;
        }
    }
    return;
    

}
void Display::d_display_full(Schedule sched){
     if(sched.the_Tasks.size() == 0){
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

    for(int i = 0; i < sched.the_Tasks.size(); i++){
       if(sched.the_Tasks[i]->get_day_in_week()==1){
        Monday.push_back(sched.the_Tasks[i]);
       }
       if(sched.the_Tasks[i]->get_day_in_week()==2){
        Tuesday.push_back(sched.the_Tasks[i]);
       }
       if(sched.the_Tasks[i]->get_day_in_week()==3){
        Wednesday.push_back(sched.the_Tasks[i]);
       }
       if(sched.the_Tasks[i]->get_day_in_week()==4){
        Thursday.push_back(sched.the_Tasks[i]);
       }
       if(sched.the_Tasks[i]->get_day_in_week()==5){
        Friday.push_back(sched.the_Tasks[i]);
       }
       if(sched.the_Tasks[i]->get_day_in_week()==6){
        Saturday.push_back(sched.the_Tasks[i]);
       }
       if(sched.the_Tasks[i]->get_day_in_week()==0){
        Sunday.push_back(sched.the_Tasks[i]);
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
void Display::display_complete(Schedule sched){

}
void Display::display_day(Schedule sched){
    cout << "Please enter day, Monday is 1, Tuesday is 2, etc.." << endl << endl;
    int day;
    cin >> day;
    string days_of_week[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    cout << "DISPLAYING DAY :" << days_of_week[day] << endl;
    int count = 1;
    for(int i = 0; i < sched.the_Tasks.size(); i++){
        if(sched.the_Tasks[i]->get_day_in_week() == day){
            cout << count << "." << endl;
            single_display(sched.the_Tasks[i]);
            count++;
        }
    }
    return;

}

void Display::single_display(Task *currtask){
    cout << currtask->get_name() << ", at " << currtask->get_date();
    cout << ", priority: " << currtask->get_priority() << endl;
    cout << "Completion Status: ";
    cout << currtask->get_status() << endl;
}

void Display::display_category(Schedule sched){
    if(sched.the_Tasks.size() == 0){
        cout << "You don't have any task. " << endl;

    return;
    }
    int count = 1;
    string category;
    cout << "Enter a category name" << endl;
    cin >> category;
    cout << "Category: " << category << endl;
    for (int i = 0; i < sched.the_Tasks.size(); i++){
        if(sched.the_Tasks.at(i)->get_category() == category){
            cout << count << "." ;
            cout << sched.the_Tasks.at(i)->get_name() << ", at " << sched.the_Tasks.at(i)->get_date();
            cout << ", at " << sched.the_Tasks.at(i)->get_hour();
            cout << ", priority: " << sched.the_Tasks.at(i)->get_priority() << endl;
            cout << "Completion Status: " << sched.the_Tasks.at(i)->get_status() << endl;
            count ++;
        }
    }
}

Display::~Display(){

}

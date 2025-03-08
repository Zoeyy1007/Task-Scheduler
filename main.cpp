#include <string>
#include <vector>
#include <iostream>
#include "Schedule.h"

using namespace std;

void Main_menu();
void Sched_options();
void Edit_event();

int main(){
    Schedule* s = new Schedule();

    string option = "";
    Main_menu();
    cin >> option;
    while(option != "q"){
        if(option == "0"){
            Main_menu();
            cin >> option;
        }
        else if(option == "1"){
            s->add_task();
            cout << "You created a new event. Enter 1 to see you current schedule, 2 to create another event, type anything else to quit" << endl;
            string op1choice1;
            cin >> op1choice1;
            //chooses to see schedule
            if(op1choice1 == "1"){
                option = "2";
            }
            //
            else if(op1choice1 == "2"){
                option = "1";
                
            }
            else{
                option = "q";
            }
            
        }
        //schedule
        else if(option == "2"){
            Sched_options();
            string op2choice1;
            cin >> op2choice1;
            if(op2choice1 == "1"){
                s->display_full();
            }
            else if(op2choice1 == "2"){
                s->display_by_category();
            }
            else if(op2choice1 == "3"){
                s->display_by_day();
            }
            else if(op2choice1 == "4"){
                s->display_by_priority();
            }
            option = "0";
        }
        else if(option == "3" && s->get_size()==0){
            option == "0";
        }
        else if(option == "3"){
            string eventName;
            cout << "Type name of task" << endl;
            cin.ignore();
            getline(cin, eventName);
            s->edit_task(eventName);
            option = "0";
        }
        else if(option == "4"){//delete a task
            string taskName;
            cout << "Please enter the name of the task you would like to delete." << endl;
            cin.ignore();
            getline(cin, taskName);
            s->remove_task(taskName);
            option = "0";
        }
        else{
            cout << "seems like you didnt pick something, pick again" << endl << endl;
            Main_menu();
            cin >> option;
        }
    }
    cout << "Thank you for using our program!" << endl;
    delete s;
    return 0;
}

void Main_menu(){
    cout << "1. Add event" << endl;
    cout << "2. View my schedule" << endl;
    cout << "3. Edit event" << endl;
    cout << "4. Delete an event" << endl;
    cout << "q. Quit" << endl;
}

void Sched_options(){
    cout << "1. View full Schedule" << endl;
    cout << "2. View Schedule by category" << endl;
    cout << "3. View schedule by day." << endl;
    cout << "4. View schedule by priority." << endl;
}


void Edit_task(){
    cout << "Edit options: " << endl;
    cout << "1. Edit task title" << endl;
    cout << "2. Edit task time" << endl;
    cout << "3. Edit task day" << endl;
    cout << "4. Delete this task" << endl;
    cout << "5. Mark as completed" << endl;
    cout << "Enter 'q' to go back to the main menu" << endl;
}
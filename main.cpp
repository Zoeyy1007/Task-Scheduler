#include <string>
#include <vector>
#include <iostream>
#include "Schedule.h"

using namespace std;

void Main_menu();
void Edit_event();
void display_option();
void Sched_options();

int main(){
    string schedule_name;
    Schedule* s = new Schedule(schedule_name);
    string option = "";
    Main_menu();
    cin >> option;
    while(option != "q"){

        //add event
        if(option == "1"){
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
                s->add_task();
                cout << "Would you like to make another?, 1 for yes, 2 for no." << endl;
                string op1choice2; 
                cin >> op1choice2;

                while(op1choice2 == "1"){
                    s->add_task();
                    cout << "Would you like to make another?, 1 for yes, 2 for no." << endl;
                    cin >> op1choice2;
                }
                
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
                string catname;

            }



        }
        else if(option == "3"){

        }
        else if(option == "4"){

        }
        else if(option == "5"){

        }
        else{
            cout << "seems like you didnt pick something, pick again" << endl << endl;
            Main_menu();
            cin >> option;
        }
    }
    cout << "Thank you for using our program!" << endl;

    return 0;
}

void Main_menu(){
    cout << "1. Add event" << endl;
    cout << "2. View my schedule" << endl;
    cout << "3. Remove event" << endl;
    cout << "4. Edit event" << endl;
    cout << "5. View Priority" << endl;
}

void Sched_options(){
    cout << "1. View full Schedule" << endl;
    cout << "2. View Schedule by category" << endl;
}


void Edit_event(){
    cout << "Edit options: " << endl;
    cout << "1. Edit event title" << endl;
    cout << "2. Edit event time" << endl;
    cout << "3. Delete this event" << endl;
    cout << "4. Mark as completed" << endl;
    cout << "Enter 'q' to go back to the previous menu" << endl;
}

void display_option(){
    cout << "How do you like to view your schedule?" << endl;
    cout << "Enter 1 to view by time. " << endl;
    cout << "Enter 2 to view by catogory" << endl;
}




#include <string>
#include <vector>
#include <iostream>
#include "Schedule.h"

using namespace std;

void Main_menu();
void Edit_event(int index, Schedule* s);
void display_option(Schedule* s);

int main(){
    string schedule_name;
    Schedule* s = new Schedule(schedule_name);
    int option = 0;
    Main_menu();
    cin >> option;
    while(option != -1){
        if(option == 6){
            Main_menu();
            cin >> option;
        }
        if(option == 1){
            s->add_task
            cout << "You created a new event. Enter 1 to see you current schedule, 2 to create another event" << endl;
            cin >> option;
        }
        if(option == 2){
            display_option(s);
            cout << "Select the event you want to edit" << endl;
            int index;
            cin >> index;
            Edit_event(index,s);
            cin >> option;
        }
    }
    return 0;
}

void Main_menu(){
    cout << "1. Add event" << endl;
    cout << "2. View my schedule" << endl;
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

#include <string>
#include <vector>
#include <iostream>
#include "Schedule.h"

using namespace std;

void Main_menu();
void add_newEvent(Schedule* s);
void Edit_event();
void display_option();

int main(){
    Schedule* s;
    int option = 0;
    Main_menu();
    cin >> option;
    if(option == 1){
        add_newEvent(s);
        cout << "You created a new event. Enter 1 to see you current schedule, 2 to create another event" << endl;
    }
    if(option == 2){
        //display events
        s->display_full();
        cout << "Select the event you want to edit by entering its number." << endl;
        cout << "Enter 'q' to go back to the main menu. " << endl;
        cout << "(Getting user input)" << endl;
        Edit_event();
    }
}

void Main_menu(){
    cout << "1. Add event" << endl;
    cout << "2. View my schedule" << endl;
}

void add_newEvent(Schedule* s){
    string title;
    string taskDate; 
    int priority;
    cout << "Please enter event title" << endl;
    cin.ignore(); //ignore the /n from last input
    getline(cin, title);
    cout << "Please enter event time" << endl;
    cin.ignore(); 
    getline(cin, taskDate);
    cout << taskDate << endl;
    cout << "What is the priority of your event" << endl;
    cin >> priority;
    cout << priority << endl;
    cout << "Enter 'q' to go back to the previous menu" << endl;
    s->add_task(title, taskDate, priority);
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



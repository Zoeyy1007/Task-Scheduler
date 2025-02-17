#include <string>
#include <vector>
#include <iostream>

using namespace std;

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


int main(){
    int option = 0;
    Main_menu();
    cin >> option;
    if(option == 1){
        cout << "Please enter event title" << endl;
        cout << "Please enter event time" << endl;
        cout << "Tag your event" << endl;
        cout << "Enter 'q' to go back to the previous menu" << endl;
        //create event
        cout << "(Getting user input)" << endl;
        cout << "You created a new event. Enter 1 to see you current schedule, 2 to create another event" << endl;
    }
    if(option == 2){
        cout << "You have following events: " << endl;
        cout << "Monday: " << endl;
        cout << "1. Homework: due 3:00PM" << endl;
        cout << "Tuesday: " << endl;
        cout << "2. Violin lesson at: 4:00PM (URGENT)" << endl;
        cout << "3. Dinner with Mom at: 5:00PM" << endl;
        cout << "Select the event you want to edit by entering its number." << endl;
        cout << "Enter 'q' to go back to the main menu. " << endl;
        cout << "(Getting user input)" << endl;
        Edit_event();
    }
}
#include "Display.h"
#include <iostream>

using namespace std;

Display::Display() {}

void Display::show_home_screen() {
    int choice = 0;
    EventManager manager;

    while (true) {
        cout << "\nHome Screen\n";
        cout << "1. Events\n";
        cout << "2. Completed Events\n";
        cout << "3. Schedule\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: show_events_menu(manager); break;
            case 2: show_completed_events_menu(manager); break;
            case 3: show_schedule_menu(manager); break;
            case 0: return;
            default: cout << "Invalid option, please try again.\n";
        }
    }
}

void Display::show_events_menu(EventManager& manager) {
    int choice = 0;
    while (true) {
        cout << "\nEvents Menu\n";
        cout << "1. Add Event\n";
        cout << "2. Remove Event\n";
        cout << "3. Mark Event Complete\n";
        cout << "4. Edit Event\n";
        cout << "0. Back to Home Screen\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: handle_add_event(manager); break;
            case 2: handle_remove_event(manager); break;
            case 3: handle_mark_complete(manager); break;
            case 4: handle_edit_event(manager); break;
            case 0: return;
            default: cout << "Invalid option, please try again.\n";
        }
    }
}

void Display::show_completed_events_menu(EventManager& manager) {
    int choice = 0;
    while (true) {
        cout << "\nCompleted Events Menu\n";
        cout << "1. Display All Completed Events\n";
        cout << "2. Sort by Category\n";
        cout << "3. Sort by Priority\n";
        cout << "4. Sort by Date\n";
        cout << "0. Back to Home Screen\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: display_event_list(manager.get_completed_events()); break;
            case 2: handle_sort_by_category(manager); break;
            case 3: handle_sort_by_priority(manager); break;
            case 4: handle_sort_by_date(manager); break;
            case 0: return;
            default: cout << "Invalid option, please try again.\n";
        }
    }
}

void Display::show_schedule_menu(EventManager& manager) {
    int choice = 0;
    while (true) {
        cout << "\nSchedule Menu\n";
        cout << "1. Display All Events\n";
        cout << "2. Sort by Category\n";
        cout << "3. Sort by Priority\n";
        cout << "4. Sort by Date\n";
        cout << "0. Back to Home Screen\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: display_event_list(manager.get_all_events()); break;
            case 2: handle_sort_by_category(manager); break;
            case 3: handle_sort_by_priority(manager); break;
            case 4: handle_sort_by_date(manager); break;
            case 0: return;
            default: cout << "Invalid option, please try again.\n";
        }
    }
}

void Display::display_event_list(const vector<Task>& events) {
    if (events.empty()) {
        cout << "No events found.\n";
    } else {
        for (const Task& event : events) {
            event.display();
        }
    }
}

void Display::handle_add_event(EventManager& manager) {
    Task newTask;
    newTask.inputTask();
    manager.add_event(newTask);
    cout << "Event added successfully.\n";
}

void Display::handle_remove_event(EventManager& manager) {
    cout << "Enter event name to remove: ";
    string eventName;
    cin.ignore();
    getline(cin, eventName);
    manager.remove_event(eventName);
}

void Display::handle_mark_complete(EventManager& manager) {
    cout << "Enter event name to mark as complete: ";
    string eventName;
    cin.ignore();
    getline(cin, eventName);
    manager.mark_event_complete(eventName);
}

void Display::handle_edit_event(EventManager& manager) {
    cout << "Enter event name to edit: ";
    string eventName;
    cin.ignore();
    getline(cin, eventName);
    manager.edit_event(eventName);
}

void Display::handle_sort_by_category(EventManager& manager) {
    cout << "Enter category to sort by: ";
    string category;
    cin.ignore();
    getline(cin, category);
    display_event_list(manager.get_events_by_category(category));
}

void Display::handle_sort_by_priority(EventManager& manager) {
    cout << "Enter priority to sort by: ";
    int priority;
    cin >> priority;
    display_event_list(manager.get_events_by_priority(priority));
}

void Display::handle_sort_by_date(EventManager& manager) {
    cout << "Enter date to sort by (MM/DD/YYYY): ";
    string date;
    cin.ignore();
    getline(cin, date);
    display_event_list(manager.get_events_by_date(date));
}

Display::~Display() {}

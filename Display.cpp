#include "Display.h"
#include <iostream>
#include <limits> 

using namespace std;

Display::Display() {}

void Display::show_home_screen() {
    EventManager manager;
    while (true) {
        cout << "\nHome Screen\n";
        cout << "1. Events\n";
        cout << "2. Completed Events\n";
        cout << "3. Schedule\n";
        cout << "0. Exit\n";
        int choice = get_valid_int_input("Enter your choice: ", 0, 3);

        if (choice == 1) {
            show_events_menu(manager);
        } else if (choice == 2) {
            show_completed_events_menu(manager);
        } else if (choice == 3) {
            show_schedule_menu(manager);
        } else if (choice == 0) {
            return;
        }
    }
}

void Display::show_events_menu(EventManager& manager) {
    while (true) {
        cout << "\nEvents Menu\n";
        cout << "1. Add Event\n";
        cout << "2. Remove Event\n";
        cout << "3. Mark Event Complete\n";
        cout << "4. Edit Event\n";
        cout << "0. Back to Home Screen\n";
        int choice = get_valid_int_input("Enter your choice: ", 0, 4);

        if (choice == 1) {
            handle_add_event(manager);
        } else if (choice == 2) {
            handle_remove_event(manager);
        } else if (choice == 3) {
            handle_mark_complete(manager);
        } else if (choice == 4) {
            handle_edit_event(manager);
        } else if (choice == 0) {
            return;
        }
    }
}

void Display::show_completed_events_menu(EventManager& manager) {
    while (true) {
        cout << "\nCompleted Events Menu\n";
        cout << "1. Display All Completed Events\n";
        cout << "2. Sort by Category\n";
        cout << "3. Sort by Priority\n";
        cout << "4. Sort by Date\n";
        cout << "0. Back to Home Screen\n";
        int choice = get_valid_int_input("Enter your choice: ", 0, 4);

        if (choice == 1) {
            display_event_list(manager.get_completed_events());
        } else if (choice == 2) {
            handle_sort_by_category(manager);
        } else if (choice == 3) {
            handle_sort_by_priority(manager);
        } else if (choice == 4) {
            handle_sort_by_date(manager);
        } else if (choice == 0) {
            return;
        }
    }
}

void Display::show_schedule_menu(EventManager& manager) {
    while (true) {
        cout << "\nSchedule Menu\n";
        cout << "1. Display All Events\n";
        cout << "2. Sort by Category\n";
        cout << "3. Sort by Priority\n";
        cout << "4. Sort by Date\n";
        cout << "0. Back to Home Screen\n";
        int choice = get_valid_int_input("Enter your choice: ", 0, 4);

        if (choice == 1) {
            display_event_list(manager.get_all_events());
        } else if (choice == 2) {
            handle_sort_by_category(manager);
        } else if (choice == 3) {
            handle_sort_by_priority(manager);
        } else if (choice == 4) {
            handle_sort_by_date(manager);
        } else if (choice == 0) {
            return;
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
    string eventName = get_valid_string_input("Enter event name to remove: ");
    manager.remove_event(eventName);
}

void Display::handle_mark_complete(EventManager& manager) {
    string eventName = get_valid_string_input("Enter event name to mark as complete: ");
    manager.mark_event_complete(eventName);
}

void Display::handle_edit_event(EventManager& manager) {
    string eventName = get_valid_string_input("Enter event name to edit: ");
    manager.edit_event(eventName);
}

void Display::handle_sort_by_category(EventManager& manager) {
    string category = get_valid_string_input("Enter category to sort by: ");
    display_event_list(manager.get_events_by_category(category));
}

void Display::handle_sort_by_priority(EventManager& manager) {
    int priority = get_valid_int_input("Enter priority to sort by: ", 1, 5);
    display_event_list(manager.get_events_by_priority(priority));
}

void Display::handle_sort_by_date(EventManager& manager) {
    string date = get_valid_string_input("Enter date to sort by (MM/DD/YYYY): ");
    display_event_list(manager.get_events_by_date(date));
}

// Helper function to validate integer input
int Display::get_valid_int_input(const string& prompt, int min, int max) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value < min || value > max) {
            cout << "Invalid input. Please enter a number between " << min << " and " << max << ".\n";
            cin.clear(); // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore remaining input
            return value;
        }
    }
}

// Helper function to validate string input
string Display::get_valid_string_input(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        if (!input.empty()) {
            return input;
        }
        cout << "Input cannot be empty. Please enter a valid value.\n";
    }
}

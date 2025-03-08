#include "Task.h"

Task::Task() : name(""), date(""), category(""), priority(0), duration(0), completed(false) {}

Task::Task(const string& name, const string& date, const string& category, int priority, int duration)
    : name(name), date(date), category(category), priority(priority), duration(duration), completed(false) {}

string Task::get_name() const { return name; }
string Task::get_date() const { return date; }
string Task::get_category() const { return category; }
int Task::get_priority() const { return priority; }
int Task::get_duration() const { return duration; }
bool Task::is_completed() const { return completed; }

// Setters
void Task::set_name(const string& newName) { name = newName; }
void Task::set_date(const string& newDate) { date = newDate; }
void Task::set_category(const string& newCategory) { category = newCategory; }
void Task::set_priority(int newPriority) { priority = newPriority; }
void Task::set_duration(int newDuration) { duration = newDuration; }
void Task::mark_complete() { completed = true; }

void Task::display() const {
    cout << "Event: " << name 
         << "\nDate: " << date
         << "\nCategory: " << category 
         << "\nPriority: " << priority
         << "\nDuration: " << duration << " minutes" // Display duration
         << "\nStatus: " << (completed ? "Completed" : "Pending") 
         << "\n" << endl;
}

void Task::inputTask() {
    cout << "Enter event name: ";
    getline(cin, name);
    cout << "Enter date (YYYY-MM-DD HH:MM): ";
    getline(cin, date);
    cout << "Enter category: ";
    getline(cin, category);
    cout << "Enter priority (1-5): ";
    cin >> priority;
    cout << "Enter duration (in minutes): ";
    cin >> duration;
    cin.ignore();
    completed = false;
}

void Task::editTask() {
    int choice;
    while (true) {
        cout << "\nEdit Event Menu:\n";
        cout << "1. Edit Name\n";
        cout << "2. Edit Date\n";
        cout << "3. Edit Category\n";
        cout << "4. Edit Priority\n";
        cout << "5. Edit Duration\n";
        cout << "6. Mark Complete\n";
        cout << "0. Done Editing\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter new name: ";
                getline(cin, name);
                break;
            case 2:
                cout << "Enter new date (YYYY-MM-DD HH:MM): ";
                getline(cin, date);
                break;
            case 3:
                cout << "Enter new category: ";
                getline(cin, category);
                break;
            case 4:
                cout << "Enter new priority (1-5): ";
                cin >> priority;
                cin.ignore();
                break;
            case 5:
                cout << "Enter new duration (in minutes): ";
                cin >> duration;
                cin.ignore();
                break;
            case 6:
                mark_complete();
                cout << "Event marked as complete.\n";
                break;
            case 0:
                return;
            default:
                cout << "Invalid option, try again.\n";
        }
    }
}

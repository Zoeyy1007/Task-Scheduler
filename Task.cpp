#include "Task.h"
#include <limits>


Task::Task() {
    this->name = "";
    this->date = "";
    this->time = "";
    this->category = "";
    this->priority = 1;
    this->duration = 0;
    this->completed = false;
}

Task::Task(const string& name, const string& date, const string& time, const string& category, int priority, int duration)
    : name(name), date(date), time(time), category(category), priority(priority), duration(duration), completed(false) {
        convert_date_int(date, year, month, day);
        convert_time_int(time, hour, min);

        if (check_valid_input() == 0)
        {
            cout << "The task is on: " << year<<"/" << month<<"/"<<day<<endl;  
        }
        else
        {
            cout << "Invalid inputs. Please reenter." << endl;
        }
    }

int Task::check_valid_input() const
{
    int not_valid = 0;
    if ((hour > 23) || (hour < 0)) //using military time
    {
        not_valid = 1;
        cout << "Invalid input of hour!" << endl;
    }
    if ((min > 59) || (min < 0))
    {
        not_valid = 1;
        cout << "Invalid input of minutes!" << endl;
    }
    if (year < 2025)
    {
        not_valid = 1;
        cout << "Invalid input of year!" << endl;
    }
    if ((month < 0) || (month > 12))
    {
        not_valid = 1;
        cout << "Invalid input of month" << endl;
    }
    if ((day < 0) || (day > 31)) //might have to account for the days exist in certain months
    {
        not_valid = 1;
        cout << "Invalid input of day!" << endl;
    }
    return not_valid;
}

string Task::get_name() const { return name; }
string Task::get_date() const { return date; }
string Task::get_category() const { return category; }
string Task::get_time() const { return time; }
int Task::get_year() const {return year;}
int Task::get_month() const {return month;}
int Task::get_day() const {return day;}
int Task::get_hour() const {return hour;}
int Task::get_min() const {return min;}
int Task::get_priority() const { return priority; }
int Task::get_duration() const { return duration; }
bool Task::is_completed() const { return completed; }

// Setters
void Task::set_name(const string& newName) { if (!newName.empty()) name = newName; }
void Task::set_date(const string& newDate) { if (!newDate.empty()) date = newDate; }
void Task::set_category(const string& newCategory) { if (!newCategory.empty()) category = newCategory; }
void Task::set_priority(int newPriority) { if (newPriority >= 1 && newPriority <= 5) priority = newPriority; }
void Task::set_duration(int newDuration) { if (newDuration > 0) duration = newDuration; }
void Task::mark_complete() { completed = true; }
void Task::set_time(const string& newTime) { if (!newTime.empty()) time = newTime; }

void Task::display() const {
    cout << "Event: " << name 
         << "\nDate: " << date
         << "\nTime: " << time  // NEW
         << "\nCategory: " << category 
         << "\nPriority: " << priority
         << "\nDuration: " << duration << " minutes"
         << "\nStatus: " << (completed ? "Completed" : "Pending") 
         << "\n" << endl;
}

void Task::inputTask() {
    cout << "Enter event name: ";
    getline(cin, name);
    
    cout << "Enter date (YYYY-MM-DD): ";
    getline(cin, date);
    convert_date_int(date, year, month, day);
    cout << "Current date is " << get_year()<< "/" << get_month() << "/" << get_day() << endl;

    cout << "Enter start time (HH:MM): ";
    getline(cin, time);
    convert_time_int(time, hour, min);
    cout << "The task is at " << hour << ":" << min << endl;
    
    cout << "Enter category: ";
    getline(cin, category);

    cout << "Enter priority (1-5): ";
    while (!(cin >> priority) || priority < 1 || priority > 5) {
        cout << "Invalid priority. Enter a value between 1 and 5: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter duration (in minutes): ";
    while (!(cin >> duration) || duration <= 0) {
        cout << "Invalid duration. Enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    cin.ignore(); // Clear newline from buffer
    completed = false;

    
    cout << "Would you like to add any Sub-events? (Y or N)";
    string subtasksans;
    cin >> subtasksans;
    if(subtasksans == "y"){
        cout << "How many sub-events would you like to add?" << endl;
        int subtasktimes;
        cin >> subtasktimes;
        while(!cin.good() || subtasktimes <= 0){
            cout << "Enter valid number starting from 0.";
            cin >> subtasktimes;
        }
        for(int i = 0; i < subtasktimes; i++){
            Subtask currsubtask;
            currsubtask.input_subtask(year, month, day, hour, min);
            subtasks.push_back(currsubtask);
        }
    }
    else{
        cout << "Understood, this event will have no sub-events." << endl;
    }
}

void Task::editTask() {
    string input;
    int intInput;

    while (true) {
        cout << "\nEdit Event Menu:\n";
        cout << "1. Edit Name\n";
        cout << "2. Edit Date\n";
        cout << "3. Edit Time\n";
        cout << "4. Edit Category\n";
        cout << "5. Edit Priority\n";
        cout << "6. Edit Duration\n";
        cout << "7. Mark Complete\n";
        cout << "q. Done Editing\n";
        cout << "Enter your choice: ";

        cin >> input;
        cin.ignore();

        if (input == "1") {
            cout << "Enter new name: ";
            getline(cin, name);
        } else if (input == "2") {
            cout << "Enter new date (YYYY-MM-DD HH:MM): ";
            getline(cin, date);
        } else if (input == "3") {
            cout << "Enter new category: ";
            getline(cin, category);
        } else if (input == "4") {
            cout << "Enter new priority (1-5): ";
            while (!(cin >> intInput) || intInput < 1 || intInput > 5) {
                cout << "Invalid priority. Enter a value between 1 and 5: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            priority = intInput;
            cin.ignore();
        } else if (input == "5") {
            cout << "Enter new duration (in minutes): ";
            while (!(cin >> intInput) || intInput <= 0) {
                cout << "Invalid duration. Enter a positive number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            duration = intInput;
            cin.ignore();
        } else if (input == "6") {
            mark_complete();
            cout << "Event marked as complete.\n";
        } else if (input == "q") {
            return;
        } else {
            cout << "Invalid option, try again.\n";
        }
    }
}

void Task::convert_date_int(const string& date, int& year, int& month, int& day){
    year = stoi(date.substr(0,4));
    month = stoi(date.substr(5,2));
    day = stoi(date.substr(8,2));
}

void Task::convert_time_int(const string& time, int& hour, int& min){
    hour = stoi(time.substr(0,2));
    min = stoi(time.substr(3,5));
}
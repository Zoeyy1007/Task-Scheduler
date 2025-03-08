#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>

using namespace std;

class Task {
private:
    string name;
    string date;
    string time; 
    string category;
    int priority;
    int duration;
    bool completed;

public:
    Task();
    Task(const string& name, const string& date, const string& time, const string& category, int priority, int duration);

    // Getters
    string get_name() const;
    string get_date() const;
    string get_time() const; 
    string get_category() const;
    int get_priority() const;
    int get_duration() const;
    bool is_completed() const;

    // Setters
    void set_name(const string& newName);
    void set_date(const string& newDate);
    void set_time(const string& newTime); 
    void set_category(const string& newCategory);
    void set_priority(int newPriority);
    void set_duration(int newDuration);
    void mark_complete();

    // Display task details
    void display() const;

    // Input and edit functions
    void inputTask();
    void editTask();
};

#endif // TASK_H

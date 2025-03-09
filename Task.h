#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>
#include <iostream>
#include "string_convert.h"
#include <vector>
#include "subtask.h"

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
    int year;
    int month;
    int day;
    int hour;
    int min;
    vector<Subtask> subtasks;

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
    int get_hour() const;
    int get_min() const;
    int get_year() const;
    int get_month() const;
    int get_day() const;

    // Setters
    void set_name(const string& newName);
    void set_date(const string& newDate);
    void set_time(const string& newTime); 
    void set_category(const string& newCategory);
    void set_priority(int newPriority);
    void set_duration(int newDuration);
    void mark_complete();
    int check_valid_input() const;
    // Display task details
    void display() const;

    // Input and edit functions
    void inputTask();
    void editTask();
};

#endif // TASK_H
#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <vector>
#include <string>
#include <iostream>
#include "Task.h"

using namespace std;

class Schedule {
private:
    vector<Task> tasks;

public:
    Schedule();
    // Task management
    void add_task(const Task& task);
    void remove_task(const string& task_name);
    void mark_task_complete(const string& task_name);
    void edit_task(const string& task_name);

    // Sorting functions
    void sort_by_date();
    void sort_by_category();
    void sort_by_priority();

    // Display functions
    void display_schedule() const;
    void display_completed_events() const;
    void display_sorted_by_category() const;
    void display_sorted_by_priority() const;

    // Getter
    vector<Task> get_all_tasks() const;

    ~Schedule();
};
#endif // SCHEDULE_H

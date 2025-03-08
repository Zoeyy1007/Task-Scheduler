#include "Schedule.h"
#include <iostream>
#include <algorithm>

using namespace std;

Schedule::Schedule() {}

void Schedule::add_task(const Task& task) {
    tasks.push_back(task);
}

void Schedule::remove_task(const string& task_name) {
    auto it = remove_if(tasks.begin(), tasks.end(), [&](const Task& task) {
        return task.get_name() == task_name;
    });

    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());
        cout << "Task \"" << task_name << "\" removed successfully.\n";
    } else {
        cout << "Task \"" << task_name << "\" not found.\n";
    }

void Schedule::mark_task_complete(const string& task_name) {
    for (Task& task : tasks) {
        if (task.get_name() == task_name) {
            task.mark_complete();
            cout << "Task \"" << task_name << "\" marked as complete.\n";
            return;
        }
    }
    cout << "Task \"" << task_name << "\" not found.\n";
}

void Schedule::edit_task(const string& task_name) {
    for (Task& task : tasks) {
        if (task.get_name() == task_name) {
            task.editTask();
            cout << "Task \"" << task_name << "\" updated successfully.\n";
            return;
        }
    }
    cout << "Task \"" << task_name << "\" not found.\n";
}

vector<Task> Schedule::get_all_tasks() const {
    return tasks;
}

void Schedule::sort_by_date() {
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.get_date() < b.get_date();
    });
}

void Schedule::sort_by_category() {
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.get_category() < b.get_category();
    });
}

void Schedule::sort_by_priority() {
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.get_priority() < b.get_priority();
    });
}

void Schedule::display_schedule() const {
    if (tasks.empty()) {
        cout << "No scheduled tasks.\n";
        return;
    }

    for (const Task& task : tasks) {
        task.display();
    }
}

void Schedule::display_completed_events() const {
    bool found = false;
    for (const Task& task : tasks) {
        if (task.is_completed()) {
            task.display();
            found = true;
        }
    }
    if (!found) {
        cout << "No completed events.\n";
    }
}

void Schedule::display_sorted_by_category() const {
    vector<Task> sortedTasks = tasks;
    sort(sortedTasks.begin(), sortedTasks.end(), [](const Task& a, const Task& b) {
        return a.get_category() < b.get_category();
    });

    if (sortedTasks.empty()) {
        cout << "No tasks available to display.\n";
        return;

    }

    for (const Task& task : sortedTasks) {
        task.display();
    }
}

void Schedule::display_sorted_by_priority() const {
    vector<Task> sortedTasks = tasks;
    sort(sortedTasks.begin(), sortedTasks.end(), [](const Task& a, const Task& b) {
        return a.get_priority() < b.get_priority();
    });
  
    if (sortedTasks.empty()) {
        cout << "No tasks available to display.\n";
        return;
    }
    for (const Task& task : sortedTasks) {
        task.display();
    }
}

Schedule::~Schedule() {}

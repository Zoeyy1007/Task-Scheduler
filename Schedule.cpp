#include "Schedule.h"
#include <iostream>
#include <algorithm>

using namespace std;

Schedule::Schedule() {}

void Schedule::add_task(const Task& task) {
    tasks.push_back(task);
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
        cout << "No scheduled tasks." << endl;
        return;
    }

    for (const Task& task : tasks) {
        task.display();
    }
}

Schedule::~Schedule() {}

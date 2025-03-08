#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "Task.h"
#include <vector>
#include <string>

using namespace std;

class EventManager {
private:
    vector<Task> events;  // List of tasks (events)

public:
    // Add event to the list
    void add_event(const Task& event);

    // Remove event based on name
    void remove_event(const string& eventName);

    // Mark event as complete
    void mark_event_complete(const string& eventName);

    // Edit event details
    void edit_event(const string& eventName);

    // Display all events
    void display_all_events() const;

    // Get all events
    vector<Task> get_all_events() const;

    // Get only completed events
    vector<Task> get_completed_events() const;

    // Filtering methods
    vector<Task> get_events_by_category(const string& category) const;
    vector<Task> get_events_by_priority(int priority) const;
    vector<Task> get_events_by_date(const string& date) const;

    // Get event duration
    int get_event_duration(const Task& event) const;
};

#endif // EVENTMANAGER_H

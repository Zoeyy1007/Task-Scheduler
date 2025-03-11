#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "Task.h"
#include <vector>
#include <string>
#include "subtask.h"

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
    bool mark_event_complete(const string& eventName);

    // Edit event details
    bool edit_event(const string& eventName);

    // Display all events
    void display_all_events() const;

    // Get all events
    vector<Task> get_all_events() const;

    // Get only completed events
    vector<Task> get_completed_events() const;
    // Get event duration
    int get_event_duration(const Task& event) const;

    int get_event_size() const {return events.size();}
};

#endif // EVENTMANAGER_H

#include "EventManager.h"
#include <iostream>
#include <algorithm>  // Needed for std::remove_if

using namespace std;

void EventManager::add_event(const Task& event) {
    events.push_back(event);
    cout << "Event \"" << event.get_name() << "\" added successfully.\n";
}

void EventManager::remove_event(const string& eventName) {
    auto it = remove_if(events.begin(), events.end(),
                        [&](const Task& event) { return event.get_name() == eventName; });

    if (it != events.end()) {
        events.erase(it, events.end());
        cout << "Event \"" << eventName << "\" removed successfully.\n";
    } else {
        cout << "Error: Event \"" << eventName << "\" not found.\n";
    }
}

bool EventManager::mark_event_complete(const string& eventName) {
    for (Task& event : events) {
        if (event.get_name() == eventName) {
            event.mark_complete();
            cout << "Event \"" << eventName << "\" marked as complete.\n";
            return true;
        }
    }
    cout << "Error: Event \"" << eventName << "\" not found.\n";
    return false;
}

bool EventManager::edit_event(const string& eventName) {
    for (Task& event : events) {
        if (event.get_name() == eventName) {
            event.editTask();
            cout << "Event \"" << eventName << "\" updated successfully.\n";
            return true;
        }
    }
    cout << "Error: Event \"" << eventName << "\" not found.\n";
    return false;
}

void EventManager::display_all_events() const {
    if (events.empty()) {
        cout << "No scheduled events.\n";
    } else {
        for (const Task& event : events) {
            event.display();
        }
    }
}

vector<Task> EventManager::get_all_events() const {
    return events;
}

vector<Task> EventManager::get_completed_events() const {
    vector<Task> completedEvents;
    for (const Task& event : events) {
        if (event.is_completed()) {
            completedEvents.push_back(event);
        }
    }
    return completedEvents;
}

vector<Task> EventManager::get_events_by_category(const string& category) const {
    vector<Task> filteredEvents;
    for (const Task& event : events) {
        if (event.get_category() == category) {
            filteredEvents.push_back(event);
        }
    }
    return filteredEvents;
}

vector<Task> EventManager::get_events_by_priority(int priority) const {
    vector<Task> filteredEvents;
    for (const Task& event : events) {
        if (event.get_priority() == priority) {
            filteredEvents.push_back(event);
        }
    }
    return filteredEvents;
}

vector<Task> EventManager::get_events_by_date(const string& date) const {
    vector<Task> filteredEvents;
    for (const Task& event : events) {
        if (event.get_date() == date) {
            filteredEvents.push_back(event);
        }
    }
    return filteredEvents;
}

int EventManager::get_event_duration(const Task& event) const {
    return event.get_duration();
}

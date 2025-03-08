#include "EventManager.h"
#include <iostream>
#include <algorithm>  // Make sure to include this for std::remove_if

using namespace std;

void EventManager::add_event(const Task& event) {
    events.push_back(event);
}

void EventManager::remove_event(const string& eventName) {
    events.erase(std::remove_if(events.begin(), events.end(),
        [&](const Task& event) { return event.get_name() == eventName; }),
        events.end());
}

void EventManager::mark_event_complete(const string& eventName) {
    for (Task& event : events) {
        if (event.get_name() == eventName) {
            event.mark_complete();
            return;
        }
    }
}

void EventManager::edit_event(const string& eventName) {
    for (Task& event : events) {
        if (event.get_name() == eventName) {
            event.editTask();
            return;
        }
    }
}

void EventManager::display_all_events() const {
    if (events.empty()) {
        cout << "No scheduled events." << endl;
        return;
    }

    for (const Task& event : events) {
        event.display();
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

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
            bool subtaskscomplete = true;
            for(int i = 0; i < event.subtasks.size(); i++){
                if(event.subtasks[i].get_completion() == false){
                    subtaskscomplete = false;
                    cout << "Subtasks titled: " << event.subtasks[i].get_name() << " is incomplete, please complete it first in order to complete this task." << endl;
                }
            }

            if(subtaskscomplete){
                event.mark_complete();
                cout << "Event \"" << eventName << "\" marked as complete.\n";
                return true;
            }
            else{
                cout << "Error: Event \"" << eventName << "\" Does not have all sub-event's completed.";
                return false;
            }
            
            
        }
    
    }
    cout << "Error: Event \"" << eventName << "\" cannot be found.";
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


int EventManager::get_event_duration(const Task& event) const {
    return event.get_duration();
}


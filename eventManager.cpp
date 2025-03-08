#include "EventManager.h"

using namespace std;

// constructor
EventManager::EventManager(const string& eventName, int start, int dur) 
    : name(eventName), startTime(start), duration(dur) {}
//allows to set length of time for each event

string EventManager::getName() const {
    return name;
}

int EventManager::getStartTime() const {
    return startTime;
}

int EventManager::getEndTime() const {
    return startTime + duration;  
}

int EventManager::getDuration() const {
    return duration;
}

// checks for time conflict 
bool EventManager::hasConflict(const EventManager& newEvent, const vector<EventManager>& events) {
    for (const EventManager& event : events) {  
        int existingStart = event.getStartTime();
        int existingEnd = event.getEndTime();
        int newStart = newEvent.getStartTime();
        int newEnd = newEvent.getEndTime();

        if (newStart < existingEnd && newEnd > existingStart) {
            cout << "Conflict with: " << event.getName() << endl;
            return true;
        }
    }
    return false;
}
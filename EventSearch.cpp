#include <iostream>
#include <vector>
#include "EventSearch.h"

using namespace std;


// search by name
vector<EventManager> EventSearch::searchByName(const vector<EventManager>& events, const string& keyword) {
    vector<EventManager> results;

    for (const EventManager& event : events) {
        string name = event.getName();
        if (name.find(keyword)) {
            results.push_back(event);
        }
    }

    return results;
}

// search by time
vector<EventManager> EventSearch::searchByStartTime(const vector<EventManager>& events, int startTime) {
    vector<EventManager> results;
    for (const EventManager& event : events) {
        if (event.getStartTime() == startTime) {
            results.push_back(event);
        }
    }
    return results;
}

// search by date 
vector<EventManager> EventSearch::searchByDate(const vector<EventManager>& events, const string& datePart) {
    vector<EventManager> results;
    for (const EventManager& event : events) {
        string eventTime = to_string(event.getStartTime());
        if (eventTime.find(datePart) == 0) {  
            results.push_back(event);
        }
    }
    return results;
}


void EventSearch::displaySearchResults(const vector<EventManager>& results) {
    if (results.empty()) {
        cout << "No matching events found." << endl;
        return;
    }

    cout << "Matching Events:" << endl;
    for (const EventManager& event : results) {
        event.displayEvent();
    }
}

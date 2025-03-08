#include "EventSearch.h"
#include "EventManager.h"
#include "Task.h"
#include <vector>
#include <string>

using namespace std;

vector<Task> EventSearch::searchByName(const vector<Task>& events, const string& name) {
    vector<Task> result;
    for (const Task& event : events) {
        if (event.get_name() == name) {
            result.push_back(event);
        }
    }
    return result;
}

vector<Task> EventSearch::searchByStartTime(const vector<Task>& events, const string& startTime) {
    vector<Task> result;
    for (const Task& event : events) {
        if (event.get_date() == startTime) {  // Assuming date includes time
            result.push_back(event);
        }
    }
    return result;
}

vector<Task> EventSearch::searchByDate(const vector<Task>& events, const string& date) {
    vector<Task> result;
    for (const Task& event : events) {
        if (event.get_date().substr(0, 10) == date) {  // Extracts only the date part (YYYY-MM-DD)
            result.push_back(event);
        }
    }
    return result;
}

#include "EventSearch.h"
#include "EventManager.h"
#include "Task.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

// Helper function to convert a string to lowercase for case-insensitive comparison
string EventSearch::toLowerCase(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

vector<Task> EventSearch::searchByName(const vector<Task>& events, const string& name) {
    vector<Task> result;
    string lowerName = toLowerCase(name);

    for (const Task& event : events) {
        if (toLowerCase(event.get_name()) == lowerName) {
            result.push_back(event);
        }
    }

    if (result.empty()) {
        cout << "No events found with the name: " << name << endl;
    }
    return result;
}

vector<Task> EventSearch::searchByStartTime(const vector<Task>& events, const string& startTime) {
    vector<Task> result;

    for (const Task& event : events) {
        if (event.get_time() == startTime) {
            result.push_back(event);
        }
    }

    if (result.empty()) {
        cout << "No events found with the start time: " << startTime << endl;
    }
    return result;
}

vector<Task> EventSearch::searchByDate(const vector<Task>& events, const string& date) {
    vector<Task> result;

    int year, month, day;
    convert_date_int(date, year, month, day);
    for (const Task& event : events) {
        if (event.get_year() == year && event.get_day() == day && event.get_month() == month) {
            result.push_back(event);
        }
    }

    if (result.empty()) {
        cout << "No events found on the date: " << date << endl;
    }
    return result;
}

vector<Task> EventSearch::searchByPriority(const vector<Task>& events, int priority) {
    vector<Task> result;

    for (const Task& event : events) {
        if (event.get_priority() == priority) { 
            result.push_back(event);
        }
    }

    if (result.empty()) {
        cout << "No events found with priority: " << priority << endl;
    }
    return result;
}

vector<Task> EventSearch::searchByCategory(const vector<Task>& events, const string& category) {
    vector<Task> result;
    string lowerCategory = toLowerCase(category);

    for (const Task& event : events) {
        // Assuming Task has get_category()
        if (toLowerCase(event.get_category()) == lowerCategory) { 
            result.push_back(event);
        }
    }

    if (result.empty()) {
        cout << "No events found in category: " << category << endl;
    }
    return result;
}

void EventSearch::convert_date_int(const string& date, int& year, int& month, int& day){
    year = stoi(date.substr(0,4));
    month = stoi(date.substr(5,2));
    day = stoi(date.substr(8,2));
}
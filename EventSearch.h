#ifndef EVENTSEARCH_H
#define EVENTSEARCH_H

#include "Task.h"
#include "EventManager.h"
#include <vector>
#include <string>

class EventSearch {
public:
    static std::vector<Task> searchByName(const vector<Task>& events, const std::string& name);
    static std::vector<Task> searchByStartTime(const vector<Task>& events, const std::string& startTime);
    static std::vector<Task> searchByDate(const vector<Task>& events, const std::string& date);
    static std::vector<Task> searchByPriority(const vector<Task>& events, int priority);
    static std::vector<Task> searchByCategory(const vector<Task>& events, const std::string& category);
    static void convert_date_int(const string& date, int& year, int& month, int& day);

private:
    static std::string toLowerCase(const std::string& str);
};

#endif // EVENTSEARCH_H

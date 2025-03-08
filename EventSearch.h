#ifndef EVENTSEARCH_H
#define EVENTSEARCH_H

#include "Task.h"
#include <vector>
#include <string>

class EventSearch {
public:
    static std::vector<Task> searchByName(const std::vector<Task>& events, const std::string& name);
    static std::vector<Task> searchByStartTime(const std::vector<Task>& events, const std::string& startTime);
    static std::vector<Task> searchByDate(const std::vector<Task>& events, const std::string& date);
};

#endif

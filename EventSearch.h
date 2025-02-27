#ifndef EVENTSEARCH_H
#define EVENTSEARCH_H

#include <iostream>
#include <vector>
#include "EventManager.h"  

class EventSearch {
public:
// search by name
    static std::vector<EventManager> searchByName(const std::vector<EventManager>& events, const std::string& keyword);

// search by time
    static std::vector<EventManager> searchByStartTime(const std::vector<EventManager>& events, int startTime);
//search by date
    static std::vector<EventManager> searchByDate(const std::vector<EventManager>& events, const std::string& datePart);

    static void displaySearchResults(const std::vector<EventManager>& results);
};

#endif // EVENTSEARCH_H

#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <iostream>
#include <vector>
#include "Schedule.h"

class EventManager {
private:
    std::string name;
    int startTime;  
    int duration;  

public:
    // Constructor
    EventManager(const string& eventName, int start, int dur);
  
    std::string getName() const;
    int getStartTime() const;
    int getEndTime() const;
    int getDuration() const;

    // checks for time conflict
    static bool hasConflict(const EventManager& newEvent, const std::vector<EventManager>& events);

    
    void displayEvent() const;
};

#endif // EVENTMANAGER_H


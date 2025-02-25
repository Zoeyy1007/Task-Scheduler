#include <iostream>
#include "events.h"
using namespace std;

string Event::getName()
{
return event_name;
}

int Event::getDate()
{
    return event_date;
}

int Event::getPriority()
{
    return event_priority;
}

int Event::get_exec_time()
{
    return event_exec_time;
}
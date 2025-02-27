#include <iostream>
#include "task.h"
using namespace std;

string Task::getName()
{
return task_name;
}

int Task::getDate()
{
    return task_date;
}

int Task::getPriority()
{
    return task_priority;
}

int Task::get_exec_time()
{
    return task_exec_time;
}
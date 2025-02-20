#include <iostream>
#include <vector>
#include "Task.h"

using namespace std;

class Schedule{
    private:
        string schedule_name;
        int size = 0;
    public:
        Schedule();
        void add_task(string taskname, string taskDate,  int priority);
        void remove_task(int num); //num-1 is its current position in the vector, num is the number displayed starting with 1
        int get_priority();
        vector<Task*> the_Tasks;
        int get_execTime();
        void display_catogorized();
        void display_full();
        bool is_active();
};


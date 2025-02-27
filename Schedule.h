#include <iostream>
#include <vector>
#include "Task.h"

using namespace std;

class Schedule{
    private:
        string schedule_name;
        int size = 0;
        vector<Task*> the_Tasks;
    public:
        Schedule();
        Schedule(string schedule_name);
        void add_task();
        void add_task(string taskname, string taskdate, int priority, string category);
        void remove_task(int num); //num-1 is its current position in the vector, num is the number displayed starting with 1
        int get_priority();
        int get_execTime();
        void display_catogorized();
        void display_full();
        bool is_active();
        void display_by_category();
        void complete_task(int index);
};


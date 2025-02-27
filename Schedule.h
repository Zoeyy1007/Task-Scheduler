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

        void add_task(string taskname,string taskDate, int priority, string category, int hour, int day);
        void remove_task(string name);

        int get_priority();
        int get_execTime();
        void display_catogorized();
        void display_full();
        void display_by_category();

        void display_by_priority();
        void complete_task(string name);
        int get_size(){return size;}
        bool is_complete(string name);

        Task* findTask(string name);
        void single_display(Task* currtask);
};


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
        Schedule()
        {
            schedule_name = "Defult Schedule";
            size = 0;
        }
        Schedule(string schedule_name)
        {
            this->schedule_name = schedule_name;
            size = 0;
        }

        //management
        void add_task();
        void add_task(string taskname,string taskDate, int priority, string category, int hour, int day, int week);
        void remove_task(string name);

        //int get_priority(); //this should be in task.h
        //int get_execTime();

        //display function 
        void display_categorized();
        void display_full();
        void display_by_category();
        void display_by_priority();
        void single_display(Task* currtask);
        void display_by_day();

        //status and edit
        void complete_task(string name);
        bool is_complete(string name);
        void edit_task(string name);

        //utility
        Task* findTask(string name);
        int get_size(){return size;}
};
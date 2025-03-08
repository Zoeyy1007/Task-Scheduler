#include <iostream>
#include <vector>
#include "Task.h"

using namespace std;


class Schedule{
    private:
        int size = 0;    
    public:
        vector<Task*> the_Tasks;
        vector<Task*> completed_Tasks;
        Schedule();
        ~Schedule();
        void add_task();

        void add_task(string taskname, int priority, string category, int month, int day, int hour);
        void remove_task(string name);

        //int get_priority(); //this should be in task.h
        //int get_execTime();

        //display function 
        void display_categorized();
        void display_full();
        void display_by_category();
        void display_by_priority();
        void complete_task(const string& name);
        int get_size(){return size;}
        bool is_complete(string name);
        void edit_task(string name);

        //utility
        Task* findTask(string name);
        void single_display(Task* currtask);
        void display_by_day();
};


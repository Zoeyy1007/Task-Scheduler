#include <iostream>
#include <vector>
#include "Task.h"

using namespace std;

class Schedule{
    private:
        int size = 0;
        vector<Task*> the_Tasks;
    public:
        Schedule();
        ~Schedule();
        void add_task();

        void add_task(string taskname, int priority, string category, int month, int day, int hour);
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
        void display_by_day();
        void edit_task(string name);
};


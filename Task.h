#include <iostream>
#include <vector>
#include "time.h"

using namespace std;

class Task{
    private:
        string title;
        string tag;
        Time Thetime;
        string status;
        vector<Task*> tasks;
    
    public:
    void Delete_Event(Task* CurrTask);
    void Event_Status(Task* CurrTask);
    Task(string title, string tag, Time Thetime, string status);
    Task();

};
#include <iostream>
#include <vector>
#include "time.h"

using namespace std;

class Tasks{
    private:
        string title;
        string tag;
        Time Thetime;
        string status;
    
    public:
    void Delete_Event(Tasks* CurrTask);
    void Event_Status(Tasks* CurrTask);
};


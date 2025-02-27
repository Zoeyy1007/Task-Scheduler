#include <iostream>
#include <vector>

using namespace std;

class Task {
    private:
        string task_name;
        string task_date;
        int priority;
        string category;
        bool task_complete = false;  // Ensure this exists
    
    public:
        Task(string taskname, string taskDate, int priority, string category);
        void complete_task();
        string get_date();
        string get_name();
        int get_priority();
        string get_category();
        bool get_status();  // ✅ Add this line if it's missing
    };
    
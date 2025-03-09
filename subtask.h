#ifndef SUBTASK_HPP
#define SUBTASK_HPP
#include <iostream>
#include <string>



using namespace std;
class Subtask {
        string name;
        string category;
        bool completion;
    public: 
        Subtask();
        //setters
        void set_completion_true();
        void set_completion_false();
        void set_name(string subname);
        void set_category(string catname);

        //getters
        bool get_completion();
        string get_name();
        string get_category();

        void input_subtask();
};
#endif 
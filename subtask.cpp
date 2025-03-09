#include "subtask.h"
#include <string>

Subtask::Subtask(){

}

 //setters
void Subtask::set_completion_true(){
    completion = true;
}
void Subtask::set_completion_false(){
    completion = true;
}

void Subtask::set_name(string subname){
    name = subname;
}

void Subtask::set_category(string catname){
    category = catname;
}

//getters
bool Subtask::get_completion(){
    return completion;
}

string Subtask::get_name(){
    return name;
}

string Subtask::get_category(){
    return category;
}

void input_subtask();

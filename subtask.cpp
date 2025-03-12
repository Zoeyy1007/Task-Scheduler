#include "subtask.h"
#include <string>
#include <iostream>
#include <iostream>
#include <vector>

Subtask::Subtask(){

}

Subtask::Subtask(string newname, string newcat, string newdesc, int tYear, int tMonth, int tDay, int tHour, int tMin){
    name = newname;
    category = newcat;
    description = newdesc;
    completion = false;
    year = tYear;
    month = tMonth;
    day = tDay;
    hour = tHour;
    min = tMin;

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

void Subtask::set_description(string newdesc){
    if(newdesc.empty()){
        cout << "You have chosen to have no description for your sub-event." << endl;
    }
    else{
        description = newdesc;
        cout << "Description entered into sub-event." << endl;
    }
}

//getters
bool Subtask::get_completion()const{
    return completion;
}

string Subtask::get_name()const{
    return name;
}

string Subtask::get_category()const{
    return category;
}

int Subtask::get_year()const{
    return year;
}

int Subtask::get_month()const{
    return month;
}

int Subtask::get_day()const{
    return day;
}

int Subtask::get_hour()const{
    return hour;
}

int Subtask::get_min() const{
    return min;
}

string Subtask::get_description() const{
    return description;
}

void Subtask::input_subtask(int tYear, int tMonth, int tDay, int tHour, int tMin){
    cout << "Enter event name: ";
    getline(cin, name);
    
    cout << "Enter category: ";
    getline(cin, category);

    cout << "Enter a description for your sub-event, if not needed just press enter: ";
    string currdesc;
    getline(cin, currdesc);
    set_description(currdesc);

    completion = false;

    year = tYear;
    month = tMonth;
    day = tDay;
    hour = tHour;
    min = tMin;
}

void Subtask::display_subtask() const{
    cout << "     Sub-event: " << name 
         << "\n     Date: " << year << "/" << month << "/" << day
         << "\n     Time: " << hour << ":" << min
         << "\n     Category: " << category 
         << "\n     Description: " << description
         << "\n     Status: " << (completion ? "Completed" : "Pending") 
         << "\n" << endl;
}


Subtask::~Subtask(){
    
}
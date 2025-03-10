#include "subtask.h"
#include <string>
#include <iostream>
#include <iostream>
#include "string_convert.h"
#include <vector>

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

void Subtask::input_subtask(int tYear, int tMonth, int tDay, int tHour, int tMin){
    cout << "Enter event name: ";
    getline(cin, name);
    
    cout << "Enter category: ";
    getline(cin, category);

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
         << "\n     Status: " << (completion ? "Completed" : "Pending") 
         << "\n" << endl;
}

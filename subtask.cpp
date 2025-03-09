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
bool Subtask::get_completion(){
    return completion;
}

string Subtask::get_name(){
    return name;
}

string Subtask::get_category(){
    return category;
}

int Subtask::get_year(){
    return year;
}

int Subtask::get_month(){
    return month;
}

int Subtask::get_day(){
    return day;
}

int Subtask::get_hour(){
    return hour;
}

int Subtask::get_min() {
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

void Subtask::display_subtask(){
    cout << "Sub-event: " << name 
         << "\nDate: " << year << "/" << month << "/" << day
         << "\nTime: " << hour << ":" << min
         << "\nCategory: " << category 
         << "\nStatus: " << (completion ? "Completed" : "Pending") 
         << "\n" << endl;
}

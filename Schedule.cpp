#include <iostream>
#include <vector>
#include "time.h"
#include "Schedule.h"

using namespace std;

Schedule::Schedule(string title, string tag, Time Thetime, string status){
    this->title = title;
    this->tag = tag; 
    this->Thetime=Thetime; 
    this->status = status;
}
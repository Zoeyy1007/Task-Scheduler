#include <iostream>
#include "category.h"
#include <string>
using namespace std;


Category::Category(string name) : name(name) {}

string Category::get_name() const { 
    return name; }
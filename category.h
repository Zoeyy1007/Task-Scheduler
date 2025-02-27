#ifndef CATEGORY_HPP
#define CATEGORY_HPP
#include <iostream>
#include <string>
using namespace std;
class Category {
    public: 
    string category_name = "";
    Category(const string& category_name) : category_name(category_name) {}
    void printCategory();
};





#endif //CATEGORY_HPP
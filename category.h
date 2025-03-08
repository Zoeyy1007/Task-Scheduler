#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>

class Category {
private:
    std::string name;

public:
    Category(std::string name);
    std::string get_name() const;
};

#endif
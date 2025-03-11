#ifndef DISPLAY_H
#define DISPLAY_H

#include "EventManager.h"
#include "EventSearch.h"
#include "Task.h"
#include <string>

class Display {
public:
    Display();
    void show_home_screen();
    void show_events_menu(EventManager& manager);
    void show_completed_events_menu(EventManager& manager);
    void show_schedule_menu(EventManager& manager);
    
    ~Display() = default;  // No need for an empty destructor

private:
    void display_event_list(const vector<Task>& events);
    void handle_add_event(EventManager& manager);
    void handle_remove_event(EventManager& manager);
    void handle_mark_complete(EventManager& manager);
    void handle_edit_event(EventManager& manager);
    void handle_sort_by_category(const vector<Task>& events);
    void handle_sort_by_priority(const vector<Task>& events);
    void handle_sort_by_date(const vector<Task>& events);
    
    int get_valid_int_input(const string& prompt, int min, int max); // Helper for integer validation
    string get_valid_string_input(const string& prompt); // Helper for string validation
};

#endif

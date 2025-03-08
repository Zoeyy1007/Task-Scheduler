#ifndef DISPLAY_H
#define DISPLAY_H

#include "EventManager.h"
#include <string>

class Display {
public:
    Display();
    void show_home_screen();
    void show_events_menu(EventManager& manager);
    void show_completed_events_menu(EventManager& manager);
    void show_schedule_menu(EventManager& manager);
    ~Display();

private:
    void display_event_list(const vector<Task>& events);
    void handle_add_event(EventManager& manager);
    void handle_remove_event(EventManager& manager);
    void handle_mark_complete(EventManager& manager);
    void handle_edit_event(EventManager& manager);
    void handle_sort_by_category(EventManager& manager);
    void handle_sort_by_priority(EventManager& manager);
    void handle_sort_by_date(EventManager& manager);
};

#endif

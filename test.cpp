#include <gtest/gtest.h>
#include "EventSearch.h"
#include "EventManager.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;
// Test Task class
TEST(TaskTest, ConstructorAndGetters) {
   Task task("Meeting", "2025-03-14", "14:00", "Work", 3, 30);
  
   EXPECT_EQ(task.get_name(), "Meeting");
   EXPECT_EQ(task.get_date(), "2025-03-14");
   EXPECT_EQ(task.get_priority(), 3);
   EXPECT_EQ(task.get_category(), "Work");
   EXPECT_EQ(task.get_month(), 3);
   EXPECT_EQ(task.get_day(), 14);
   EXPECT_EQ(task.get_hour(), 14);
   EXPECT_FALSE(task.is_completed());  // Task should be incomplete initially
}

TEST(TaskTest, SetterMethods) {
    Task task("Initial", "2025-03-10", "09:00", "Work", 5, 10);
  
    task.set_name("Updated Meeting");
    task.set_date("2025-03-11");
    task.set_time("16:00");
    task.set_priority(3);
    task.set_category("Personal");
    task.set_duration(25);

    EXPECT_EQ(task.get_name(), "Updated Meeting");
    EXPECT_EQ(task.get_date(), "2025-03-11");
    EXPECT_EQ(task.get_time(), "16:00");
    EXPECT_EQ(task.get_priority(), 3);
    EXPECT_EQ(task.get_category(), "Personal");
    EXPECT_EQ(task.get_duration(), 25);
}

TEST(TaskTest, CompleteTask) {
    Task task("Workout", "2025-03-10", "07:00", "Health", 7, 2);
    EXPECT_FALSE(task.is_completed());

    task.mark_complete();
    EXPECT_TRUE(task.is_completed());
}

// Test Schedule class
TEST(EventManagerTests, AddAndFindTask) {

   EventManager manager;
   EventSearch searchMethod;
   Task currTask = Task("Doctor Appointment", "2025-03-10", "13:25", "Health", 4, 40);
   manager.add_event(currTask);
  
   vector<Task> v = searchMethod.searchByName(manager.get_all_events(), "Doctor Appointment");
   Task foundTask = v[0];

   EXPECT_EQ(foundTask.get_name(), "Doctor Appointment");
   EXPECT_EQ(foundTask.get_date(), "2025-03-10");
   EXPECT_EQ(foundTask.get_priority(), 4);
   EXPECT_EQ(foundTask.get_category(), "Health");
   EXPECT_EQ(foundTask.get_day(), 10);
   EXPECT_EQ(foundTask.get_hour(), 13);
   EXPECT_EQ(foundTask.get_duration(), 40);
   EXPECT_EQ(foundTask.get_min(), 25);
    EXPECT_EQ(foundTask.get_month(), 3);
}

TEST(EventManagerTests, RemoveTask) {
    EventManager manager;
    ostringstream ss;
    streambuf* get_cout = cout.rdbuf();
    cout.rdbuf(ss.rdbuf());
    EventSearch searchMethod;
    Task currTask = Task("Doctor Appointment", "2025-03-10", "13:25", "Health", 4, 40);
    manager.add_event(currTask);

    manager.remove_event("Doctor Appointment");
    //cout.rdbuf(get_cout);
    //string output1 = ss.str();
    ss.str("");
    ss.clear();
    vector<Task> v = searchMethod.searchByName(manager.get_all_events(), "Doctor Appointment");
    cout.rdbuf(get_cout);

    string output = ss.str();

    EXPECT_TRUE(v.empty());
    //EXPECT_EQ(output1, "Event \"Doctor Appointment\" removed successfully.\n");
    EXPECT_EQ(output, "No events found with the name: Doctor Appointment\n");
}

TEST(EventManagerTests, CompleteTask) {
    EventManager manager;
    EventSearch searchMethod;
    Task currTask = Task("Homework", "2025-03-18", "10:25", "School", 3, 40);
    manager.add_event(currTask);
  
   EXPECT_FALSE(currTask.is_completed());
   manager.mark_event_complete("Homework");
   vector<Task> v = searchMethod.searchByName(manager.get_all_events(), "Homework");
    currTask = v[0];
   EXPECT_TRUE(currTask.is_completed());
}


TEST(EventManagerTests, EditTaskManually) {
    EventManager manager;
    EventSearch searchMethod;
    Task currTask = Task("Homework", "2025-03-18", "10:25", "School", 3, 40);
    manager.add_event(currTask);

    istringstream input("Homework\n2\n2025-03-20\nq\n"); //stimulate input
    
    cin.rdbuf(input.rdbuf());
    streambuf* buffer = cout.rdbuf();

    manager.edit_event("Homework");

    vector<Task> v = searchMethod.searchByName(manager.get_all_events(), "Homework");
    EXPECT_EQ(v[0].get_date(), "2025-03-20");
}

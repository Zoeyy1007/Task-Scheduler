#include <gtest/gtest.h>
#include "EventSearch.h"
#include "EventManager.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;
// Test Task class
TEST(TaskTest, ConstructorAndGetters) {
   Task task("Drive", "2025-07-29", "12:00", "Work", 5, 30);
   EXPECT_EQ(task.get_name(), "Drive");
   EXPECT_EQ(task.get_date(), "2025-07-29");
   EXPECT_EQ(task.get_priority(), 5);
   EXPECT_EQ(task.get_category(), "Work");
   EXPECT_EQ(task.get_month(), 7);
   EXPECT_EQ(task.get_day(), 29);
   EXPECT_EQ(task.get_hour(), 30);
   EXPECT_FALSE(task.is_completed()); 
}

TEST(TaskTest, ConstructorAndGetters2) {
    Task task("Drive", "2025-07-29", "12:00", "Work", 5, 30);
  
    EXPECT_EQ(task.get_name(), "Drive");
    EXPECT_EQ(task.get_date(), "2025-07-29");
    EXPECT_EQ(task.get_time(), "12:00");
    EXPECT_EQ(task.get_priority(), 5);
    EXPECT_EQ(task.get_category(), "Work");
    EXPECT_EQ(task.get_duration(), 30);
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
TEST(EventSearchTest, AddAndFindTaskName) {
   EventSearch search;
   Task task("Workout", "2025-03-10", "07:00", "Health", 7, 2);
   vector<Task>tasks;
   tasks.push_back(task);
   vector<Task> result = search.searchByStartTime(tasks, "12:00");
  
   EXPECT_EQ(result[0].get_name(), "Workout");
}
TEST(EventSearchTest, AddandFindTaskDate) {
    EventSearch search;
   Task task("Workout", "2025-03-10", "07:00", "Health", 7, 2);
   vector<Task>tasks;
   tasks.push_back(task);
   vector<Task> result = search.searchByDate(tasks, "2025-03-10");
   EXPECT_EQ(result[0].get_date(), "2025-03-10");
}

TEST(EventSearchTest, AddandFindTaskPriority) {
    EventSearch search;
   Task task("Workout", "2025-03-10", "07:00", "Health", 7, 2);
   vector<Task>tasks;
   tasks.push_back(task);
   vector<Task> result = search.searchByPriority(tasks, 7);
   EXPECT_EQ(result[0].get_priority(), 7);
}

TEST(EventSearchTest, AddandFindTaskCategory) {
    EventSearch search;
    Task task("Workout", "2025-03-10", "07:00", "Health", 7, 2);
    vector<Task>tasks;
    tasks.push_back(task);
    vector<Task> result = search.searchByCategory(tasks, "Health");
    EXPECT_EQ(result[0].get_category(), "Health");
}

TEST(EventManager, RemoveTask) {
    EventManager *event= new EventManager();
    Task task("Gym", "2025-05-01", "13:00", "Fitness", 2, 30);
    event->add_event(task);
    event->remove_event("Gym");
    EXPECT_EQ(event->get_event_size(), 0);
}

TEST(ScheduleTest, DurationTask) {
   EventManager *manager = new EventManager();
   Task task("Homework", "2025-04-10", "12:00", "School", 3, 40);
   manager->add_event(task);
  EXPECT_EQ(manager->get_event_duration(task), 40);
}


TEST(TaskTest, EditTask) {
   Task* task = new Task("Homework", "2025-04-10", "12:00", "School", 3, 40);
   ASSERT_NE(task, nullptr);
   task->set_name("Updated Conference");
   task->set_date("2025-04-02");
   task->set_priority(7);
  
   ASSERT_NE(task, nullptr);
   EXPECT_EQ(task->get_name(), "Updated Conference");
   EXPECT_EQ(task->get_date(), "2025-04-02");
   EXPECT_EQ(task->get_priority(), 3);
}

TEST(scheduleTestSuite, testemptySchedule){
    EventManager *event= new EventManager();
    EXPECT_EQ(event->get_event_size(), 0);
    delete event;
}

TEST(scheduleTestSuite, testIsCompleted){
    EventManager* event = new EventManager();
    Task task("birthday", "2026-04-29","3:00","Life", 2, 12);
    event->add_event(task); 
    event->mark_event_complete("birthday");
    EXPECT_TRUE(event->mark_event_complete("birthday"));
}

TEST(RmTaskTests, Remove1Task){
    EventManager* event = new EventManager();
    Task task("Drive", "2025-07-29", "12:00", "Work", 5, 30);
    event->add_event(task); 
    event->remove_event("Drive");
    EXPECT_EQ(event->get_event_size(), 0);
    delete event;
}


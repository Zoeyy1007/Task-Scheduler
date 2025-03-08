#include <gtest/gtest.h>
#include "EventSearch.h"
#include "EventManager.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Schedule.h"


// Test Task class
TEST(TaskTest, ConstructorAndGetters) {
   Task task("Meeting", "2025-03-10 14:00", 5, "Work", 1, 14, 2);
  
   EXPECT_EQ(task.get_name(), "Meeting");
   EXPECT_EQ(task.get_date(), "2025-03-10 14:00");
   EXPECT_EQ(task.get_priority(), 5);
   EXPECT_EQ(task.get_category(), "Work");
   EXPECT_EQ(task.get_day(), 1);
   EXPECT_EQ(task.get_hour(), 14);
   EXPECT_FALSE(task.get_status());  // Task should be incomplete initially
}


TEST(TaskTest, SetterMethods) {
   Task task("Initial", "2025-03-10 14:00", 5, "Work", 1, 14, 2);
  
   task.set_name("Updated Meeting");
   task.set_date("2025-03-11 15:00");
   task.set_priority(8);
   task.set_category("Personal");
   task.set_day(3);
   task.set_hour(16);


   EXPECT_EQ(task.get_name(), "Updated Meeting");
   EXPECT_EQ(task.get_date(), "2025-03-11 15:00");
   EXPECT_EQ(task.get_priority(), 8);
   EXPECT_EQ(task.get_category(), "Personal");
   EXPECT_EQ(task.get_day(), 3);
   EXPECT_EQ(task.get_hour(), 16);
}


TEST(TaskTest, CompleteTask) {
   Task task("Workout", "2025-03-10 18:00", 7, "Health", 2, 18, 2);
   EXPECT_FALSE(task.get_status());


   task.complete_task();
   EXPECT_TRUE(task.get_status());
}


// Test Schedule class
TEST(ScheduleTest, AddAndFindTask) {
   Schedule schedule;
   schedule.add_task("Doctor Appointment", "2025-03-15 10:00", 9, "Health", 10, 3, 1);
  
   Task* foundTask = schedule.findTask("Doctor Appointment");
   ASSERT_NE(foundTask, nullptr);
   EXPECT_EQ(foundTask->get_name(), "Doctor Appointment");
   EXPECT_EQ(foundTask->get_date(), "2025-03-15 10:00");
   EXPECT_EQ(foundTask->get_priority(), 9);
   EXPECT_EQ(foundTask->get_category(), "Health");
   EXPECT_EQ(foundTask->get_day(), 10);
   EXPECT_EQ(foundTask->get_hour(), 3);
}


TEST(ScheduleTest, RemoveTask) {
   Schedule schedule;
   schedule.add_task("Gym", "2025-03-12 07:00", 6, "Fitness", 7, 7, 2);
  
   Task* foundTask = schedule.findTask("Gym");
   ASSERT_NE(foundTask, nullptr);  // Task should exist before removal
  
   schedule.remove_task("Gym");
   foundTask = schedule.findTask("Gym");
   EXPECT_EQ(foundTask, nullptr);  // Task should be removed
}


TEST(ScheduleTest, CompleteTask) {
   Schedule schedule;
   schedule.add_task("Homework", "2025-03-14 20:00", 8, "Study", 5, 20, 3);
  
   EXPECT_FALSE(schedule.is_complete("Homework"));
  
   schedule.complete_task("Homework");
   EXPECT_TRUE(schedule.is_complete("Homework"));
}

TEST(scheduleTestSuite, testIsCompleted){
    Schedule* s = new Schedule();
    s->add_task("birthday", 6, "home", 10, 2, 12); //birthday on 10/02, priority 6, starts from 12
    s->complete_task("birthday");
    EXPECT_TRUE(s->is_complete("birthday"));


TEST(ScheduleTest, EditTask) {
   Schedule schedule;
   schedule.add_task("Conference", "2025-04-01 09:00", 10, "Work", 4, 9, 1);


   Task* task = schedule.findTask("Conference");
   ASSERT_NE(task, nullptr);
  
   task->set_name("Updated Conference");
   task->set_date("2025-04-02 10:00");
   task->set_priority(7);
  
   Task* updatedTask = schedule.findTask("Updated Conference");
   ASSERT_NE(updatedTask, nullptr);
   EXPECT_EQ(updatedTask->get_name(), "Updated Conference");
   EXPECT_EQ(updatedTask->get_date(), "2025-04-02 10:00");
   EXPECT_EQ(updatedTask->get_priority(), 7);
}


TEST(RmTaskTests, Remove1Task){
    Schedule* s = new Schedule();
    s->add_task("birthday", 6, "home", 10, 2, 12); //birthday on 10/02, priority 6, starts from 12
    s->remove_task("birthday");
    EXPECT_EQ(s->get_size(), 0);
}
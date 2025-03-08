#include <gtest/gtest.h>
#include "EventSearch.h"
#include "EventManager.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Schedule.h"

// Test Task class
TEST(TaskTest, ConstructorAndGetters) {
<<<<<<< HEAD
   Task task("Meeting", 5, "Work", 03, 14, 2);
  
   EXPECT_EQ(task.get_name(), "Meeting");
   EXPECT_EQ(task.get_date(), "3/14");
   EXPECT_EQ(task.get_priority(), 5);
   EXPECT_EQ(task.get_category(), "Work");
   EXPECT_EQ(task.get_month(), 3);
   EXPECT_EQ(task.get_day(), 14);
   EXPECT_EQ(task.get_hour(), 2);
   EXPECT_FALSE(task.get_status());  // Task should be incomplete initially
=======
    Task task("Meeting", "2025-03-10", "14:30", "Work", 5, 15);
  
    EXPECT_EQ(task.get_name(), "Meeting");
    EXPECT_EQ(task.get_date(), "2025-03-10");
    EXPECT_EQ(task.get_time(), "14:30");
    EXPECT_EQ(task.get_priority(), 5);
    EXPECT_EQ(task.get_category(), "Work");
    EXPECT_EQ(task.get_duration(), 15);
>>>>>>> origin/master
}

TEST(TaskTest, SetterMethods) {
<<<<<<< HEAD
   Task task("Initial", 5, "Work", 03, 15, 2);
  
   task.set_name("Updated Meeting");
   task.set_month(4);
   task.set_priority(8);
   task.set_category("Personal");
   task.set_month(4);
   task.set_day(3);
   task.set_hour(16);


   EXPECT_EQ(task.get_name(), "Updated Meeting");
   EXPECT_EQ(task.get_date(), "4/3");
   EXPECT_EQ(task.get_priority(), 8);
   EXPECT_EQ(task.get_category(), "Personal");
   EXPECT_EQ(task.get_day(), 3);
   EXPECT_EQ(task.get_hour(), 16);
=======
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
>>>>>>> origin/master
}

TEST(TaskTest, CompleteTask) {
<<<<<<< HEAD
   Task task("Workout", 3, "Health", 2, 18, 2);
   EXPECT_FALSE(task.get_status());
=======
    Task task("Workout", "2025-03-10", "07:00", "Health", 7, 2);
    EXPECT_FALSE(task.is_completed());
>>>>>>> origin/master

    task.mark_complete();
    EXPECT_TRUE(task.is_completed());
}

// Test Schedule class
TEST(ScheduleTest, AddAndFindTask) {

   Schedule schedule;
   schedule.add_task("Doctor Appointment", 8, "Health", 3, 10, 13);
  
   Task* foundTask = schedule.findTask("Doctor Appointment");
   ASSERT_NE(foundTask, nullptr);
   EXPECT_EQ(foundTask->get_name(), "Doctor Appointment");
   EXPECT_EQ(foundTask->get_date(), "3/10");
   EXPECT_EQ(foundTask->get_priority(), 9);
   EXPECT_EQ(foundTask->get_category(), "Health");
   EXPECT_EQ(foundTask->get_day(), 10);
   EXPECT_EQ(foundTask->get_hour(), 3);
}

    vector<Task> tasks = schedule.get_all_tasks();
    ASSERT_FALSE(tasks.empty());

    const Task& foundTask = tasks.front();
    EXPECT_EQ(foundTask.get_name(), "Doctor Appointment");
    EXPECT_EQ(foundTask.get_date(), "2025-03-15");
    EXPECT_EQ(foundTask.get_time(), "10:00");
    EXPECT_EQ(foundTask.get_priority(), 9);
    EXPECT_EQ(foundTask.get_category(), "Health");
}

TEST(ScheduleTest, RemoveTask) {
<<<<<<< HEAD
   Schedule schedule;
   schedule.add_task("Gym", 6, "Fitness", 3, 7, 2);
=======
    Schedule schedule;
    Task newTask("Gym", "2025-03-12", "18:30", "Fitness", 6, 15);
    schedule.add_task(newTask);
>>>>>>> origin/master
  
    schedule.remove_task("Gym");

    vector<Task> tasks = schedule.get_all_tasks();
    auto it = find_if(tasks.begin(), tasks.end(), [](const Task& t) { return t.get_name() == "Gym"; });
     // Task should not exist
    EXPECT_EQ(it, tasks.end()); 
}

TEST(ScheduleTest, CompleteTask) {
<<<<<<< HEAD
   Schedule schedule;
   schedule.add_task("Homework", 8, "Study", 5, 20, 3);
  
   EXPECT_FALSE(schedule.is_complete("Homework"));
  
   schedule.complete_task("Homework");
   EXPECT_TRUE(schedule.is_complete("Homework"));
}

TEST(scheduleTestSuite, testIsCompleted){
    Schedule* s = new Schedule();
    s->add_task("birthday", 6, "home", 3, 2, 12); //birthday on 03/02, priority 6, starts from 12
    s->complete_task("birthday");
    EXPECT_TRUE(s->is_complete("birthday"));
}

TEST(ScheduleTest, EditTask) {
   Schedule schedule;
   schedule.add_task("Conference", 10, "Work", 3, 9, 16);


   Task* task = schedule.findTask("Conference");
   ASSERT_NE(task, nullptr);
  
   task->set_name("Updated Conference");
   //task->set_date("2025-04-02 10:00");
   task->set_priority(7);
  
   Task* updatedTask = schedule.findTask("Updated Conference");
   ASSERT_NE(updatedTask, nullptr);
   EXPECT_EQ(updatedTask->get_name(), "Updated Conference");
   EXPECT_EQ(updatedTask->get_date(), "2025-04-02 10:00");
   EXPECT_EQ(updatedTask->get_priority(), 7);
=======
    Schedule schedule;
    Task newTask("Homework", "2025-03-14", "20:00", "Study", 8, 2);
    schedule.add_task(newTask);

    schedule.mark_task_complete("Homework");


    vector<Task> tasks = schedule.get_all_tasks();
    auto it = find_if(tasks.begin(), tasks.end(), [](const Task& t) { return t.get_name() == "Homework"; });

    ASSERT_NE(it, tasks.end());
    EXPECT_TRUE(it->is_completed());
}

TEST(ScheduleTest, EditTaskManually) {
    Schedule schedule;
    Task newTask("Conference", "2025-04-01", "13:00", "Work", 10, 2);
    schedule.add_task(newTask);

    vector<Task> tasks = schedule.get_all_tasks();
    for (Task& task : tasks) {
        if (task.get_name() == "Conference") {
            task.set_name("Updated Conference");
            task.set_date("2025-04-02");
            task.set_time("15:00");
            task.set_priority(7);
        }
    }

    auto it = find_if(tasks.begin(), tasks.end(), [](const Task& t) { return t.get_name() == "Updated Conference"; });

    ASSERT_NE(it, tasks.end());
    EXPECT_EQ(it->get_date(), "2025-04-02");
    EXPECT_EQ(it->get_time(), "15:00");
    EXPECT_EQ(it->get_priority(), 7);
>>>>>>> origin/master
}


TEST(RmTaskTests, Remove1Task){
    Schedule* s = new Schedule();
    //birthday on 10/02, priority 6, starts from 12
    s->add_task("birthday", 6, "home", 10, 2, 12); 
    s->remove_task("birthday");
    EXPECT_EQ(s->get_size(), 0);
}

TEST(scheduleTestSuite, testemptySchedule){
    Schedule* s = new Schedule();
    EXPECT_THROW(s->display_full(), runtime_error);
}
TEST(scheduleTestSuite, testIsCompleted){
    Schedule* s = new Schedule();
    s->add_task("birthday", 6, "home", 10, 2, 12); //birthday on 10/02, priority 6, starts from 12
    s->complete_task("birthday");
    EXPECT_TRUE(s->is_complete("birthday"));
}


TEST(RmTaskTests, Remove1Task){
    Schedule* s = new Schedule();
    s->add_task("birthday", 6, "home", 10, 2, 12); //birthday on 10/02, priority 6, starts from 12
    s->remove_task("birthday");
    EXPECT_EQ(s->get_size(), 0);
}
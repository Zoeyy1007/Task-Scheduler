#include <gtest/gtest.h>
#include "Task.h"
#include "Schedule.h"

// Test Task class
TEST(TaskTest, ConstructorAndGetters) {
    Task task("Meeting", "2025-03-10", "Work", 5, 15);
  
    EXPECT_EQ(task.get_name(), "Meeting");
    EXPECT_EQ(task.get_date(), "2025-03-10");
    EXPECT_EQ(task.get_priority(), 5);
    EXPECT_EQ(task.get_category(), "Work");
    EXPECT_EQ(task.get_duration(), 15);
   }

TEST(TaskTest, SetterMethods) {
    Task task("Initial", "2025-03-10", "Work", 5, 10);
  
    task.set_name("Updated Meeting");
    task.set_date("2025-03-11");
    task.set_priority(3);
    task.set_category("Personal");
    task.set_duration(25);

    EXPECT_EQ(task.get_name(), "Updated Meeting");
    EXPECT_EQ(task.get_date(), "2025-03-11");
    EXPECT_EQ(task.get_priority(), 3);
    EXPECT_EQ(task.get_category(), "Personal");
    EXPECT_EQ(task.get_duration(), 25);
}

TEST(TaskTest, CompleteTask) {
    Task task("Workout", "2025-03-10", "Health", 7, 2);
    EXPECT_FALSE(task.is_completed());

    task.mark_complete();
    EXPECT_TRUE(task.is_completed());
}

// Test Schedule class
TEST(ScheduleTest, AddAndFindTask) {
    Schedule schedule;
    Task newTask("Doctor Appointment", "2025-03-15", "Health", 9, 10);
    schedule.add_task(newTask);

    vector<Task> tasks = schedule.get_all_tasks();
    ASSERT_FALSE(tasks.empty());

    const Task& foundTask = tasks.front();
    EXPECT_EQ(foundTask.get_name(), "Doctor Appointment");
    EXPECT_EQ(foundTask.get_date(), "2025-03-15");
    EXPECT_EQ(foundTask.get_priority(), 9);
    EXPECT_EQ(foundTask.get_category(), "Health");
}

TEST(ScheduleTest, RemoveTask) {
    Schedule schedule;
    Task newTask("Gym", "2025-03-12", "Fitness", 6, 15);
    schedule.add_task(newTask);
  
    schedule.remove_task("Gym");

    vector<Task> tasks = schedule.get_all_tasks();
    auto it = find_if(tasks.begin(), tasks.end(), [](const Task& t) { return t.get_name() == "Gym"; });

    EXPECT_EQ(it, tasks.end());  // Task should not exist
}

TEST(ScheduleTest, CompleteTask) {
    Schedule schedule;
    Task newTask("Homework", "2025-03-14", "Study", 8, 2);
    schedule.add_task(newTask);

    schedule.mark_task_complete("Homework");

    vector<Task> tasks = schedule.get_all_tasks();
    auto it = find_if(tasks.begin(), tasks.end(), [](const Task& t) { return t.get_name() == "Homework"; });

    ASSERT_NE(it, tasks.end());
    EXPECT_TRUE(it->is_completed());
}

TEST(ScheduleTest, EditTask) {
    Schedule schedule;
    Task newTask("Conference", "2025-04-01", "Work", 10, 2);
    schedule.add_task(newTask);

    schedule.edit_task("Conference");

    vector<Task> tasks = schedule.get_all_tasks();
    auto it = find_if(tasks.begin(), tasks.end(), [](const Task& t) { return t.get_name() == "Conference"; });

    ASSERT_NE(it, tasks.end());
    // Further manual verification needed for edit functionality
}

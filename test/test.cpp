#include "gtest/gtest.h"
#include "../Schedule.h"  // Include Schedule header
#include "../Task.h" 
#include <iostream>
#include <sstream>

using namespace std;


TEST(ScheduleTest, AddTaskWithParams) {
    Schedule schedule;

    // Add task using function
    schedule.add_task("Meeting", "2025-03-05", 3, "Work");

    // Get the task list
    auto tasks = schedule.getTasks(); // Assuming Schedule has getTasks() returning vector<Task*>
    ASSERT_EQ(tasks.size(), 1); 

    Task* task = tasks[0]; 

    // Verify task details
    EXPECT_EQ(task->get_name(), "Meeting");
    EXPECT_EQ(task->get_date(), "2025-03-05");
    EXPECT_EQ(task->get_priority(), 3);
    EXPECT_EQ(task->get_category(), "Work");


}



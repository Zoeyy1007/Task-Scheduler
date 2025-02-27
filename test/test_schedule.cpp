#include "../Schedule.h"
#include "gtest/gtest.h"

TEST(ScheduleTest, AddTaskIncreasesSize) {
    Schedule schedule;
    int initialSize = schedule.get_size();
    
    schedule.add_task("Meeting", "2025-03-10", 3, "Work");

    EXPECT_EQ(schedule.get_size(), initialSize + 1);
}

TEST(ScheduleTest, AddTaskCorrectAttributes) {
    Schedule schedule;
    schedule.add_task("Write report", "2025-03-05", 4, "School");

    ASSERT_EQ(schedule.get_size(), 1);  // Verify task was added

    Task* addedTask = schedule.get_task(0);  // Retrieve the first task

    ASSERT_NE(addedTask, nullptr);  // Ensure task exists
    EXPECT_EQ(addedTask->get_name(), "Write report");
    EXPECT_EQ(addedTask->get_date(), "2025-03-05");
    EXPECT_EQ(addedTask->get_priority(), 4);
    EXPECT_EQ(addedTask->get_category(), "School");
}

TEST(ScheduleTest, AddTaskHandlesInvalidPriority) {
    Schedule schedule;
    schedule.add_task("Invalid Task", "2025-03-15", -2, "Misc");

    Task* addedTask = schedule.get_task(0);  
    ASSERT_NE(addedTask, nullptr);

    EXPECT_GE(addedTask->get_priority(), 1); // Ensure priority is adjusted correctly
}
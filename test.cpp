#include "gtest/gtest.h"
#include "Schedule.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

TEST(scheduleTestSuite, testemptySchedule){
    Schedule* s = new Schedule();
    EXPECT_THROW(s->display_full(), runtime_error);
}
TEST(scheduleTestSuite, testIsCompleted){
    Schedule* s = new Schedule();
    s->add_task("birthday", "october 2", 4, "bday", 5, 2);
}

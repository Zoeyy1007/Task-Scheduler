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


#include <gtest/gtest.h>
#include "Schedule.h"
#include <iostream>
#include <sstream>

using namespace std;

TEST(DeleteFuncTests, DeleteInNonEmptySchedule){
    Schedule* s = new Schedule();

    s->add_task("physics lab", "02-27-2025", 1, "School work");
    s->remove_task(1);
    EXPECT_EQ(s->get_size(), 0);
}

TEST(DeleteFuncTests, DeleteInEmptySchedule){
    stringstream buffer;
    streambuf* Output = cout.rdbuf(buffer.rdbuf());
    Schedule* s = new Schedule();
    s->remove_task(0);

    cout .rdbuf(Output);
    string output = buffer.str();

    EXPECT_EQ(output, "Invalid input\n");
}

TEST(CompleteTaskFuncTests, IncompletedToComplete){
    Schedule* s = new Schedule();
    s->add_task("physics lab", "02-27-2025", 1, "School work");
    s->complete_task(1);
    
    EXPECT_TRUE(s->is_complete(1));
}

TEST(CompleteTaskFuncTests, NegativeIndex){
    stringstream buffer;
    streambuf* Output = cout.rdbuf(buffer.rdbuf());
    Schedule* s = new Schedule();
    s->add_task("physics lab", "02-27-2025", 1, "School work");
    s->complete_task(-1);
    
    cout .rdbuf(Output);
    string output = buffer.str();
    EXPECT_EQ(output, "Invalid input\n");
}
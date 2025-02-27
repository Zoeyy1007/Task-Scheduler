cmake_minimum_required(VERSION 3.20)

add_subdirectory(test/googletest)


add_executable(run_test
  test/test_schedule.cpp
  Schedule.cpp
  Task.cpp
)
target_link_libraries(run_test gmock gtest gtest_main)
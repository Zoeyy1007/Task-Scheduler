
cmake_minimum_required(VERSION 3.20)

add_subdirectory(test/googletest)

add_executable(runtest
  test/test.cpp
  Schedule.cpp
  Task.cpp
  
)

target_link_libraries(runtest gmock gtest gtest_main)

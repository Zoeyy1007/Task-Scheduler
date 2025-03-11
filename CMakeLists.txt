cmake_minimum_required(VERSION 3.20)
project(TaskScheduler)
enable_testing()

ADD_SUBDIRECTORY(googletest)

add_executable(run
  main.cpp
  Task.cpp
  subtask.cpp
  Display.cpp
  eventManager.cpp
  EventSearch.cpp
  string_convert.cpp
)

add_executable(debug
  test.cpp 
  Task.cpp 
  eventManager.cpp
  EventSearch.cpp
  subtask.cpp
  string_convert.cpp
)

TARGET_LINK_LIBRARIES(debug gtest gtest_main)
TARGET_COMPILE_DEFINITIONS(debug PRIVATE gtest_disable_pthreads=ON)
add_test(NAME DebugTests COMMAND debug)
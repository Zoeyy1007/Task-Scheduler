cmake_minimum_required(VERSION 3.20)
project(TaskScheduler)
enable_testing()

ADD_SUBDIRECTORY(googletest)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS --coverage)

add_executable(run
  main.cpp
  Task.cpp
  subtask.cpp
  Display.cpp
  eventManager.cpp
  EventSearch.cpp
  subtask.cpp
)

add_executable(debug
  test.cpp 
  subtask.cpp
  eventManager.cpp
  EventSearch.cpp
  Display.cpp
  Task.cpp 
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-g -O0 --coverage) # Enable debugging and coverage
    add_link_options(--coverage)           # Link with coverage
endif()

TARGET_LINK_LIBRARIES(debug gtest gtest_main)
TARGET_COMPILE_DEFINITIONS(debug PRIVATE gtest_disable_pthreads=ON)
enable_testing()
add_test(NAME DebugTests COMMAND debug)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
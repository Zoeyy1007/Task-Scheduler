cmake_minimum_required(VERSION 3.20)


ADD_SUBDIRECTORY(googletest)


add_executable(run
  main.cpp
  Schedule.cpp
  Task.cpp
)

add_executable(debug
  test2.cpp
  Schedule.cpp 
  Task.cpp 
)

TARGET_LINK_LIBRARIES(debug gtest gtest_main)
TARGET_COMPILE_DEFINITIONS(debug PRIVATE gtest_disable_pthreads=ON)


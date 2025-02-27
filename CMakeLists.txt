
cmake_minimum_required(VERSION 3.20)

add_subdirectory(googletest)

add_executable(run
  main.cpp
  Schedule.cpp
  Task.cpp
)

add_executable(debug
  main.cpp 
  Schedule.cpp 
  Task.cpp 
)

add_executable(interface
  interface.cpp
  Schedule.cpp
  Task.cpp
)

add_executable(test
  test/test.cpp
  Schedule.cpp
  Task.cpp
)

target_link_libraries(test gmock gtest gtest_main)

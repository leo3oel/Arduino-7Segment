cmake_minimum_required(VERSION 3.14)

set(This SegmentTest)

project(${This} CXX)

set(Sources
  TestBasicSegment.cpp
  TestSingleDigitSevenSegment.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    Arduino-7Segment
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
cmake_minimum_required(VERSION 3.28)

set(This Arduino-7Segment)

project(${This} CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)

enable_testing()

add_subdirectory(Import/googletest)

set(Headers
  BasicSegment.h
  SingleDigitSevenSegment.h
  TwoDigitSevenSegment.h
)
set(Sources
  BasicSegment.cpp
  SingleDigitSevenSegment.cpp
  TwoDigitSevenSegment.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)
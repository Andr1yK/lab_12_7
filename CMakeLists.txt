cmake_minimum_required(VERSION 3.14)
project(ap_lab)

set(CMAKE_CXX_STANDARD 11)

add_executable(
  demo
  src/main.cpp
)

add_subdirectory(
  "${CMAKE_CURRENT_SOURCE_DIR}/gtest"
  gtest
)

enable_testing()

add_executable(
  unittest
  test/unittest.cpp
)

target_link_libraries(
  unittest
  gtest gtest_main
)

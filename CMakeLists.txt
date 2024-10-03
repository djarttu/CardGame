cmake_minimum_required(VERSION 3.16.0)
project(CardGame)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(googletest EXCLUDE_FROM_ALL)
enable_testing()

add_executable(CardGame ./main.cpp ./Deck.cpp)

add_executable(Tests ./CardGameUnitTests.cpp ./Deck.cpp)

target_link_libraries(
  Tests
  GTest::gtest_main
)



cmake_minimum_required(VERSION 3.26)
project(aoc2023)

set(CMAKE_CXX_STANDARD 23)
find_package(re2 CONFIG REQUIRED)

add_executable(aoc2023 main.cpp)
add_executable(day01part1 day1/day1part1.cpp)
add_executable(day01part2 day1/day1part2.cpp)
add_executable(day2part1 day2/day2part1.cpp)
target_link_libraries(day2part1 PRIVATE re2::re2)

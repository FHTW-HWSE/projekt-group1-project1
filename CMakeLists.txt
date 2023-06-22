cmake_minimum_required(VERSION 3.5.1)
project(Project1Group1)

set(CMAKE_C_STANDARD 99)

find_package(Catch2 REQUIRED)

add_executable(test_app src/utils.cpp test/unit_tests.cpp)

add_executable(release_app src/utils.cpp src/project1group1.cpp)

target_link_libraries(test_app Catch2::Catch2)

# Link with the math library
target_link_libraries(test_app m)
# Link with the math library
target_link_libraries(release_app m)

cmake_minimum_required(VERSION 3.5.1)
project(Project1Group1)

set(CMAKE_C_STANDARD 99)

add_executable(test_app src/utils.c test/unit_tests.c)

add_executable(release_app src/utils.c src/project1group1.c)
# Link with the math library
target_link_libraries(test_app m)
# Link with the math library
target_link_libraries(release_app m)
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <stdio.h>
#include "../src/utils.hpp"

TEST_CASE( "First run", "[test]" ) {
    printf("Generating 5 fictional students to log into a CSV-File:\n"
    "Lisa Mueller T-9876543\n"
    "David Schmidt T-1234567\n"
    "Julia Wagner T-2468135\n"
    "Alexander Keller T-5555555\n"
    "Sophia Fischer T-7777777\n\n");

    Student test_students[] = { 
        {"Lisa Mueller", "T-9876543"}, 
        {"David Schmidt", "T-1234567"}, 
        {"Julia Wagner", "T-2468135"}, 
        {"Alexander Keller", "T-5555555"},
        {"Sophia Fischer", "T-7777777"} };

    printf("Creating/Overwriting local file 'student_write_test.csv' and entering student data\n\n");
    save_students(test_students, 5, "./student_write_test.csv");
    
    printf("Checking if the file has been created\n");
    FILE* student_list = NULL;
    student_list = fopen("./student_write_test.csv", "r");
    REQUIRE( student_list != NULL );
    printf("Check OK\n\n");
    fclose(student_list);

    printf("Loading students from the CSV file back into the program\n");
    Student students_from_file[MAX_TOKEN_LEN]; // MAX_TOKEN_LEN in case something goes seriously wrong. Only 5 actually needed
    int returned_student_count = load_students(students_from_file, "./student_write_test.csv");
    REQUIRE( returned_student_count == 5 );
    printf("All 5 students got recognized\nLoaded content:\n");
    for (int i  = 0; i < 5; i++)
        printf("%s %s", students_from_file[i].name, students_from_file[i].id);

}

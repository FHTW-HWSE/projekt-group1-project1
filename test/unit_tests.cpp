#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <stdio.h>
#include "../src/utils.hpp"

TEST_CASE( "First run", "[test]") {
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
    printf("ok\n\n"
           "Verifying data\n");
    SECTION("Student loaded from file") {
        int i = GENERATE(0,1,2,3,4);
        
        REMOVE_NEWLINE(students_from_file[i].name);
        REMOVE_NEWLINE(students_from_file[i].id);
    
        REQUIRE(strcmp(students_from_file[i].name, test_students[i].name) == 0);
        REQUIRE(strcmp(students_from_file[i].id, test_students[i].id) == 0);
    }
    printf("ok\n\n"
           "Testing occupation patterns\n");
    const int rows  = 3;
    const int seats = 3;
    Seat test_classroom[MAX_ROWS][MAX_SEATS];

    printf("Full\n");
    fully_occupied(test_classroom, rows, seats);
    for(int r = 0; r < rows; r++) {
        for (int s = 0; s < seats; s++) {
            REQUIRE(test_classroom[r][s].available == 1);
        }
    }
    
    printf("Half\n");
    half_occupied(test_classroom, rows, seats);
    int available = 0;
    for(int r = 0; r < rows; r++) {
        for (int s = 0; s < seats; s++) {
            REQUIRE(test_classroom[r][s].available == available);
            available = !available;
        }
    }
    
    printf("Quarter\n");
    quarter_occupied(test_classroom, rows, seats);
    for(int r = 0; r < rows; r++) {
        for (int s = 0; s < seats; s++) {
            if ((r == 0 || r == 2) && s == 1)
                REQUIRE(test_classroom[r][s].available == 1);
            else
                REQUIRE(test_classroom[r][s].available == 0);
        }
    }
    SECTION("select_layout"){
        printf("ok\n\n"
            "Please enter 1 for the next promt\n");
        CHECK(select_layout() == QUARTER);
        
        printf("\n\nPlease enter 2 for the next promt\n");
        CHECK(select_layout() == HALF);
        
        printf("\n\nPlease hit Enter for the next promt\n");
        CHECK(select_layout() == FULL);
    }
    printf("\n\nAssigning seats\n"
           "Full\n");
    fully_occupied(test_classroom, rows, seats);
    for (int i = 0; i < 5; i++)
        assign_seat(test_classroom, rows, seats, students_from_file[i]);
    REQUIRE(strcmp(test_classroom[0][0].student.name, test_students[0].name) == 0);
    REQUIRE(strcmp(test_classroom[0][0].student.id, test_students[0].id) == 0);

    REQUIRE(strcmp(test_classroom[0][1].student.name, test_students[1].name) == 0);
    REQUIRE(strcmp(test_classroom[0][1].student.id, test_students[1].id) == 0);

    REQUIRE(strcmp(test_classroom[0][2].student.name, test_students[2].name) == 0);
    REQUIRE(strcmp(test_classroom[0][2].student.id, test_students[2].id) == 0);

    REQUIRE(strcmp(test_classroom[1][0].student.name, test_students[3].name) == 0);
    REQUIRE(strcmp(test_classroom[1][0].student.id, test_students[3].id) == 0);

    REQUIRE(strcmp(test_classroom[1][1].student.name, test_students[4].name) == 0);
    REQUIRE(strcmp(test_classroom[1][1].student.id, test_students[4].id) == 0);

    printf("Half\n");
    half_occupied(test_classroom, rows, seats);
    for (int i = 0; i < 5; i++)
        assign_seat(test_classroom, rows, seats, students_from_file[i]);
    REQUIRE(strcmp(test_classroom[0][1].student.name, test_students[0].name) == 0);
    REQUIRE(strcmp(test_classroom[0][1].student.id, test_students[0].id) == 0);

    REQUIRE(strcmp(test_classroom[1][1].student.name, test_students[1].name) == 0);
    REQUIRE(strcmp(test_classroom[1][1].student.id, test_students[1].id) == 0);

    REQUIRE(strcmp(test_classroom[1][2].student.name, test_students[2].name) == 0);
    REQUIRE(strcmp(test_classroom[1][2].student.id, test_students[2].id) == 0);

    REQUIRE(strcmp(test_classroom[2][1].student.name, test_students[3].name) == 0);
    REQUIRE(strcmp(test_classroom[2][1].student.id, test_students[3].id) == 0);

    printf("Quarter\n");
    quarter_occupied(test_classroom, rows, seats);
    for (int i = 0; i < 5; i++)
        assign_seat(test_classroom, rows, seats, students_from_file[i]);
    REQUIRE(strcmp(test_classroom[0][1].student.name, test_students[0].name) == 0);
    REQUIRE(strcmp(test_classroom[0][1].student.id, test_students[0].id) == 0);

    REQUIRE(strcmp(test_classroom[2][1].student.name, test_students[1].name) == 0);
    REQUIRE(strcmp(test_classroom[2][1].student.id, test_students[1].id) == 0);

    printf("ok\n\nTesting seat_exist\n");
    SECTION("seat_exist true") {
        int r = GENERATE(0,1,2);
        SECTION("seat_exist true") {
            int s = GENERATE(0,1,2);
            REQUIRE(seat_exist(r, s, test_classroom, rows, seats) == 1);
        }
    }

    SECTION("seat_exist false") {
        int r = GENERATE(-3,-2,-1,3,4,5);
        SECTION("seat_exist false") {
            int s = GENERATE(0,1,2);
            REQUIRE(seat_exist(r, s, test_classroom, rows, seats) == 0);
        }
    }

    SECTION("seat_exist false") {
        int r = GENERATE(0,1,2);
        SECTION("seat_exist false") {
            int s = GENERATE(-3,-2,-1,3,4,5);
            REQUIRE(seat_exist(r, s, test_classroom, rows, seats) == 0);
        }
    }
}

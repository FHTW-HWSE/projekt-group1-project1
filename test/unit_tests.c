#include "../src/project1group1.h"

#include <string.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void) {

    /* Unit test */
    Student students[MAX_STUDENTS];
    char test_path[] = "/home/student/HWSE/CProjektSS23/projekt-group1-project1/sample.csv";
    int student_count  = 3;
    
    strcpy(students[0].name, "Karin");
    strcpy(students[0].id, "78452189");
    
    strcpy(students[1].name, "Eteri");
    strcpy(students[1].id, "358456121");
    
    strcpy(students[2].name, "Samin");
    strcpy(students[2].id, "85468431");
    
    save_students(students, student_count, test_path);
    
    /* Informationen aus der Datei lesen und in das student-Array eintragen und die Anzahl der rausgelesenen Schueler speichern (return-Wert) */
    student_count = load_students(students, test_path);
    
    /* Ausgeben der gespeicheren Informationen */
    printf("%d Schueler geladen.\n\n", student_count);
    
    for (int i = 0; i < student_count; i++) {
        printf("Name: %s\nID: %s\n\n", students[i].name, students[i].id);
    }

    /* Unit Test select_layout */

    printf("Unit Test der Funktion select_layout\n"
           "====================================\n\n"
           "Geben Sie nach der Aufforderung '1' ein.\n\n");
    
    if(select_layout() == QUATER) {
        printf("\nUnit Test bestanden.\n");
    } else {
        printf("\nEtwas ist nicht nach Plan gelaufen.\n");
    }

    printf("\n\n***** Geben Sie nach der Aufforderung '2' ein. *****\n\n");

    if(select_layout() == HALF) {
         printf("\nUnit Test bestanden.\n");
    } else {
        printf("\nEtwas ist nicht nach Plan gelaufen.\n");
    }

    printf("***** Geben Sie nach der Aufforderung Enter ein. *****\n\n");
    
    if(select_layout() == FULL) {
         printf("\nUnit Test bestanden.\n");
    } else {
        printf("\nEtwas ist nicht nach Plan gelaufen.\n");
    }


    printf("Unit-testing seating patterns\n");

    int rows = 5;
    int seats = 3;
    Seat room[MAX_ROWS][MAX_SEATS]={0};

    fully_occupied(room, rows, seats);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < seats; j++)
            printf("Sitzplatznummernausgabe: %d ", room[i][j].available);


    printf("Half occupied:\n\n");
    // Generating seating pattern for half occupied
    half_occupied(room, MAX_ROWS, seats);

    for (int r = 0; r < MAX_ROWS; r++)
    {
        for (int s = 0; s < seats; s++)
        {
            printf(" %d ", room[r][s].available);
        }
        printf("\n");
    }
    
    
    for (int r = 0; r < MAX_ROWS; r++)
    {
        for (int s = 0; s < MAX_SEATS; s++)
        {
            room[r][s].available = 0;
        }
    }
    
    
    printf("\n\n\nQuarter occupied:\n\n");
    // Generating seating pattern for half occupied
    quarter_occupied(room, MAX_ROWS, seats);

    for (int r = 0; r < MAX_ROWS; r++)
    {
        for (int s = 0; s < seats; s++)
        {
            printf(" %d ", room[r][s].available);
        }
        printf("\n");
    }

    return 0;
}
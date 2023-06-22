#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "project1group1.hpp"

int main(void) {
    Seat room[MAX_ROWS][MAX_SEATS];
    char user_input[MAX_TOKEN_LEN];
    int rows = 0;
    int seats = 0;

    printf("1) Neue Pruefung erstellen\n2)Sitznachbarn abfragen\n>");
    fgets(user_input,MAX_TOKEN_LEN,stdin);

    while (user_input[0] != '1' && user_input[0] != '2') {
        printf("\nBitte wiederholen Sie die Eingabe: ");
        fgets(user_input,MAX_TOKEN_LEN,stdin);
    }

    if (user_input[0] == '1') {
        
        char date[MAX_TOKEN_LEN];
        char time[MAX_TOKEN_LEN];
        char exam_name[MAX_TOKEN_LEN];
        char room_id[MAX_TOKEN_LEN];
        printf("Bitte geben Sie folgende Daten der Pruefung ein\n");

        printf("Datum (JJJJMMTT): ");
        fgets(date,MAX_TOKEN_LEN,stdin);
        date[strlen(date)-1] = '\0';
        printf("Uhrzeit (HHMM): ");
        fgets(time,MAX_TOKEN_LEN,stdin);
        time[strlen(time)-1] = '\0';
        printf("Raumnummer: ");
        fgets(room_id,MAX_TOKEN_LEN,stdin);
        room_id[strlen(room_id)-1] = '\0';
        printf("Name: ");
        fgets(exam_name,MAX_TOKEN_LEN,stdin);
        exam_name[strlen(exam_name)-1] = '\0';


        char test_id[MAX_TOKEN_LEN] = {0};
        strcat(test_id, date);
        strcat(test_id, time);
        strcat(test_id, room_id);
        strcat(test_id, exam_name);
        strcat(test_id, "-T");

        printf("Ihre Test-ID lautet: %s. Diese Kennung wird fuer zukuenftige abfragen benoetigt.\n", test_id);

        printf("Wie viele Sitzreihen befinden sich im Hoersaal: ");
        fgets(user_input, MAX_TOKEN_LEN, stdin);
        rows = atoi(user_input);
        printf("Wie viele Sitze gibt es pro Reihe: ");
        fgets(user_input, MAX_TOKEN_LEN, stdin);
        seats = atoi(user_input);
        Selection selection  = select_layout();

        switch (selection)
        {
        case FULL:
            fully_occupied(room, rows, seats);
            break;
        
        case HALF:
            half_occupied(room, rows, seats);
            break;
        
        case QUATER:
            quarter_occupied(room, rows, seats);
            break;
        }

        strcat(test_id, ".csv");
        FILE* exam_file = fopen(test_id, "w");
        fprintf(exam_file, "%s,%s,%s,%s,%d,%d,%s", date, time, room_id, selection == FULL ? "FULL" : selection == HALF ? "HALF" : "QUARTER", rows, seats, exam_name);
        fclose(exam_file);

        test_id[strlen(test_id)-5] = 'S';

        FILE* student_file = fopen(test_id, "w");
        while (true)
        {    
            Student student;
            printf("Naechster Student (Vorname Nachname)\nGeben Sie eine Null ein um die Eingabe zu beenden: ");
            fgets(user_input,MAX_TOKEN_LEN,stdin);
            user_input[strlen(user_input)-1] = '\0';
            if (user_input[0] == '0') break;
            strcpy(student.name, user_input);
            fprintf(student_file, "%s,", user_input);
            printf("Studierendenkennung (ID): ");
            fgets(user_input,MAX_TOKEN_LEN,stdin);
            user_input[strlen(user_input)-1] = '\0';
            strcpy(student.id, user_input);
            fprintf(student_file, "%s", user_input);
            if (assign_seat(room, rows, seats, student) == 0) {
                printf("Saal voll.\n");
                break;
            } else {
                fprintf(student_file, "\n");
            }
        }
        fclose(student_file);

    }

    if (user_input[0] == '2') {
        int found = 0;
        FILE* exam_file;
        FILE* student_file;
        while(!found) {
            printf("Bitte geben Sie die Pruefungs-ID an: ");
            fgets(user_input,MAX_TOKEN_LEN,stdin);

            strcat(user_input, ".csv");

            exam_file = fopen(user_input, "r");

            if (strlen(user_input) > 5) {
                user_input[strlen(user_input)-5] = 'S';
            }

            student_file = fopen(user_input, "r");
            
            if (student_file == NULL || exam_file == NULL) {
                printf("Datei nicht gefunden.\n");
            } else {
                found = 1;
            }
        }

        char line_buffer[100];
        int index = 0;
        char *token_buffer;
        
        fgets(line_buffer, sizeof(line_buffer), exam_file);
        
        token_buffer = strtok(line_buffer, ",");
        token_buffer = strtok(NULL, ",");
        token_buffer = strtok(NULL, ",");
        token_buffer = strtok(NULL, ",");
        
        rows = atoi(token_buffer);
        
        token_buffer = strtok(NULL, ",");
        
        seats = atoi(token_buffer);
        
        token_buffer = strtok(NULL, ",");
        
        if (strcmp(token_buffer, "FULL")) {
            fully_occupied(room, rows, seats);
        }
        else if (strcmp(token_buffer, "HALF")) {
            half_occupied(room, rows, seats);
        }
        else {
            quarter_occupied(room, rows, seats);
        }
        
        while(!feof(student_file)) {
            Student student;
            fgets(line_buffer, sizeof(line_buffer), student_file);
            
            token_buffer = strtok(line_buffer, ",");
            
            strcpy(student.name, token_buffer);
            
            token_buffer = strtok(NULL, ",");
            strcpy(student.id, token_buffer);
            assign_seat(room, rows, seats, student);
        }

        while(!found) { 
            printf("Name vom Studenten: ");
            fgets(user_input,MAX_TOKEN_LEN,stdin);

            for (int r = 0; r < rows; r++) {
                for (int s = 0; s < seats; s++) {
                    if (strcmp(user_input, room[r][s].student.name) == 0) {
                        found = 1;
                        printf("Direkte Nachbarn:\n");
                        direct_neighbours(r, s, room, rows, seats);
                        printf("Indirekte Nachbarn:\n");
                        indirect_neighbours(r, s, room, rows, seats);
                    }
                }
            }
            if (!found) printf("Kein Treffer gefunden.\n");
        }
    }
    /*
    rows = atoi(user_input);
    printf("Bitte geben Sie an wieviele Sitze es pro Reihe gibt:\n\n");
    fgets(user_input,MAX_TOKEN_LEN,stdin);
    seats = atoi(user_input);// Schleife mit Error fehlt noch
    
    Selection selection = select_layout();
    */



    return 0;
}


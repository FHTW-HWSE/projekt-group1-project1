#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "utils.hpp"

int main(void) {
    Seat room[MAX_ROWS][MAX_SEATS];
    char user_input[MAX_TOKEN_LEN];
    int rows = 0;
    int seats = 0;

    printf("1) Neue Pruefung erstellen (Eingabe 1)\n2) Sitznachbarn abfragen (Eingabe 2)\n>");
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
        printf("Name der Pruefung: ");
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
        int student_limit = rows * seats;
        switch (selection)
        {
        case FULL:
            fully_occupied(room, rows, seats);
            break;
        
        case HALF:
            student_limit /= 2;
            half_occupied(room, rows, seats);
            break;
        
        case QUARTER:
            student_limit /= 4;
            quarter_occupied(room, rows, seats);
            break;
        }

        strcat(test_id, ".csv");
        FILE* exam_file = fopen(test_id, "w");
        fprintf(exam_file, "%s,%s,%s,%s,%d,%d,%s", date, time, room_id, selection == FULL ? "FULL" : selection == HALF ? "HALF" : "QUARTER", rows, seats, exam_name);
        fclose(exam_file);

        test_id[strlen(test_id)-5] = 'S';

        FILE* student_file = fopen(test_id, "w");

        
        int student_counter = 0;
        while (1)
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
            student_counter++;
            if (assign_seat(room, rows, seats, student) == 0 || student_counter >= student_limit) {
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
        FILE* exam_file = NULL;
        FILE* student_file = NULL;
        while(!found) {
            printf("Bitte geben Sie die Pruefungs-ID an: ");
            fgets(user_input,MAX_TOKEN_LEN,stdin);
            user_input[strlen(user_input)-1] = '\0';
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
        char *token_buffer;
        
        fgets(line_buffer, sizeof(line_buffer), exam_file);
        
        printf("\nPruefungsteilehmer:\n");

        token_buffer = strtok(line_buffer, ",");
        token_buffer = strtok(NULL, ",");
        token_buffer = strtok(NULL, ",");
        token_buffer = strtok(NULL, ",");
        
        char occupation[MAX_TOKEN_LEN];

        strcpy(occupation, token_buffer);
        
        token_buffer = strtok(NULL, ",");

        rows = atoi(token_buffer);
        
        token_buffer = strtok(NULL, ",");
        
        seats = atoi(token_buffer);
        
        if (strcmp(occupation, "FULL") == 0) {
            fully_occupied(room, rows, seats);
        }
        else if (strcmp(occupation, "HALF") == 0) {
            half_occupied(room, rows, seats);
        }
        else {
            quarter_occupied(room, rows, seats);
        }

        while(!feof(student_file)) {
            Student student;
            
            fgets(line_buffer, sizeof(line_buffer), student_file);
            
            if(strlen(line_buffer) > 0 && line_buffer[strlen(line_buffer)-1] == '\n')
                line_buffer[strlen(line_buffer)-1] = '\0';
            
            token_buffer = strtok(line_buffer, ",");
            
            printf("Name: \"%s\" ", token_buffer);

            strcpy(student.name, token_buffer);
            token_buffer = strtok(NULL, ",");
            
            printf("ID: \"%s\"\n", token_buffer);
            
            strcpy(student.id, token_buffer);
            
            assign_seat(room, rows, seats, student);
        }
        
        while(1) {
            found = 0;
            printf("Name vom Studenten\nGeben Sie eine Null ein um die Eingabe zu beenden: ");
            fgets(user_input,MAX_TOKEN_LEN,stdin);
            user_input[strlen(user_input)-1] = '\0';
            if (user_input[0] == '0') break;

            for (int r = 0; r < rows; r++) {
                for (int s = 0; s < seats; s++) {
                    if (strcmp(user_input, room[r][s].student.name) == 0) {
                        found = 1;
                        printf("Direkte Nachbarn: ");
                        direct_neighbours(r, s, room, rows, seats);
                        printf("\nIndirekte Nachbarn: ");
                        indirect_neighbours(r, s, room, rows, seats);
                    }
                }
            }
            if (!found) printf("Kein Treffer gefunden.\n");
        }
    }
    
    return 0;
}


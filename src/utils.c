#include "project1group1.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

/**
 * @brief Fordert den Benutzer auf eine Auswahl zu treffen, wie stark der Saal ausgelastet werden soll. Drei Moeglichkeiten stehen zur Auswahl.
 * @return Die Auswahl des Benutzers als Typ enum Selection
*/
Selection select_layout() {
    printf("Sie haben die Moeglichkeit eine Auslastungsrate fuer den Hoersaal zu waehlen.\n"
            "Wird keine Auswahl getroffen, gibt es keine Einschraenkungen und es wird eine 100%% Auslastung des Hoersaals generiert.\n\n"
            "Sie koennen nun waehlen:\n"
            "1 fuer eine 25%% Auslastung.\n"
            "2 fuer eine 50%% Auslastung.\n"
            "Enter fuer eine volle Auslastung.\n"
            "Bitte waehlen: ");

    char user_input[MAX_TOKEN_LEN];

    fgets(user_input, MAX_TOKEN_LEN, stdin);

    while((user_input[0] > '3' || user_input[0] < '1') && user_input[0] != '\n'){
        printf("Ungueltige Eingabe.\nBitte waehlen: ");
        fgets(user_input, MAX_TOKEN_LEN, stdin);
    }

    if (user_input[0] == '1') {
        printf("Es wird nun eine Auslastungsrate von 25%% generiert.");
        return QUATER;
    }
    if (user_input[0] == '2') {
        printf("Es wird nun eine Auslastungsrate von 50%% generiert.");
        return HALF;
    }
    
    printf("Sie haben keine Auswahl getroffen. Der Hoersaal kann komplett belegt werden.");
    return FULL;
}

void prompt_student(Student* studentseat){
    printf("Bitte geben Sie den Namen ein:");
    fgets(studentseat->name, MAX_TOKEN_LEN,stdin);
    printf("Bitte geben Sie die Student-ID ein:");
    fgets(studentseat->id, MAX_TOKEN_LEN,stdin);
}

/**
 * @brief Liest eine CSV-Datei aus, in der Schuelernamen- und Kennungen gespeichert sind und speichert jeden Schueler in ein Element vom Typen student
 * @param students Ein Array aus struct students, welches grosz genug sein muss um jeden Schueler speichern zu koennen
 * @param file_path Ein String der den Pfad zur Datenbank beinhaltet
 * @return Die Anzahl der gespeicherten Studenten
*/
int load_students(Student students[], char file_path[]) {
    
    FILE* student_list = fopen(file_path, "r");
    if (student_list == NULL) {
        printf("Datenbank nicht gefunden.\n");
        return 0;
    }
    
    char line_buffer[100];
    int index = 0;
    
    char *token_buffer; // Speichert einen Teil vom String. Z.B. "Eteri" aus "Eteri,123456"
    
    while(!feof(student_list)) {
        fgets(line_buffer, sizeof(line_buffer), student_list);
        
        token_buffer = strtok(line_buffer, ",");
        strcpy(students[index].name, token_buffer);
        
        token_buffer = strtok(NULL, ",");
        strcpy(students[index].id, token_buffer);

        index++;
        
        if (index > MAX_STUDENTS)
            return index;
    }
    
    fclose(student_list);
    
    return index;
}

void save_students(Student students[], int student_count, char file_path[]) {
    FILE* student_list = fopen(file_path, "w");
    if (student_list == NULL) {
        printf("Datenbank konnte nicht generiert werden.\n");
        return;
    }
    
    for (int i  = 0; i < student_count; i++) {
        fprintf(student_list, "%s,%s", students[i].name, students[i].id);
        if (i < student_count-1) fprintf(student_list, "\n");
    }
    fclose(student_list);
}

int seat_exist(int row, int seat, Seat room[][MAX_SEATS], int rows, int seats) {
    int exist = 1;
    if (row < 0 || seat < 0 || row > rows || seat > seats) {
        exist = 0;
    }
    
    return exist;
}

/**
 * @brief Gets coordinates for a seat of a student and prints out all direct neighbors
 * @param row The row of the desired student
 * @param seat The seat number of the desired student
 * @param room A 2D-array consisting of the maximum possible numbers of seats and rows
 * @param rows The number of rows according to the actual size of the room in use
 * @param seats The number of seats according to the actual size of the room in use
*/
void direct_neighbours(int row, int seat, Seat room[][MAX_SEATS], int rows, int seats) {
    for(int i = 1; i<3; i++){
        for(int j = 1; j<3; j++){
            if(room[row+(int)pow(-1,j)][seat+(int)pow(-1,i)].student.id[0] != 0){
                printf("%s, ",room[row+(int)pow(-1,j)][seat+(int)pow(-1,i)].student.name);
            }
        }
    }
    for(int i = 1; i<3; i++){
        if(room[row+(int)pow(-1,i)][seat].student.id[0] != 0){
            printf("%s, ",room[row+(int)pow(-1,i)][seat].student.name);
        }
    }
    /*
    Check index boundries
    */
}

void indirect_neighbours(int row, int seat, Seat room[][MAX_SEATS], int rows, int seats) {
    for(int i = 1; i<3; i++){
        for(int j = 1; j<3; j++){
            if(room[row+(int)pow(-1,j)][seat+2*(int)pow(-1,i)].student.id[0] != 0){
                printf("%s, ",room[row+(int)pow(-1,j)][seat+2*(int)pow(-1,i)].student.name);
            }
        }
    }
    
    for(int i = 1; i<3; i++){
        for(int j = 1; j<3; j++){
            if(room[row+2*(int)pow(-1,j)][seat+(int)pow(-1,i)*(int)pow(2,i-1)].student.id[0] != 0){
                printf("%s, ",room[row+2*(int)pow(-1,j)][seat+(int)pow(-1,i)*(int)pow(2,i-1)].student.name);
            }
        }
    }

    for(int i = 1; i<3; i++){
        if(room[row+2*(int)pow(-1,i)][seat].student.id[0] != 0){
            printf("%s, ",room[row+2*(int)pow(-1,i)][seat].student.name);
        }
    }

    for(int i = 1; i<3; i++){
        if(room[row][seat+2*(int)pow(-1,i)].student.id[0] != 0){
            printf("%s, ",room[row][seat+2*(int)pow(-1,i)].student.name);
        }
    }
    /*
    Check index boundries
    */
}

/**
 * @brief Generiert ein Belegungsmuster fuer eine volle Auslastung des Hoersaals
 * @param room Ein 2D-Array mit dem Attribut available fuer die Verfuegbarkeit
 * @param rows Die Anzahl an Sitzreihen des Saals
 * @param seats Die Anzahl der Sitze pro Sitzreihe
*/
void fully_occupied(Seat room[][MAX_SEATS], int rows, int seats) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < seats; j++)
            room[i][j].available = 1;
}

void half_occupied(Seat room[][MAX_SEATS], int rows, int seats) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < seats; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 1) {
                    room[i][j].available = 1;
                }
            } else {
                if (j % 2 == 0) {
                    room[i][j].available = 1;
                }
            }
        }
}

void quarter_occupied(Seat room[][MAX_SEATS], int rows, int seats) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < seats; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 1) {
                    room[i][j].available = 1;
                }
            }
        }
}

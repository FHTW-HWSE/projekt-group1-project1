#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS     20
#define MAX_SEATS    20
#define MAX_STUDENTS MAX_ROWS * MAX_SEATS

#define MAX_TOKEN_LEN 100

typedef struct {
    char name[MAX_TOKEN_LEN];
    char id[MAX_TOKEN_LEN];
} student;

int load_students(student students[], char file_path[]) {
    
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
    
    return index;
}

interpret_student_line(char* line)

typedef struct(){
Alber Prechtl
}student expected

struct* resut = interpret
Albert Prechtl*\

int main(void) {
    
    /* Unit test */
    
    /* Anlegen eines Arrays mit der maximale zulaessigen Schueleranzahl */
    student students[MAX_STUDENTS];
    
    /* Dateipfad von einer Test-CSV-Datei definieren */
    char test_path[] = "./sample.csv";
    
    /* Informationen aus der Datei lesen und in das student-Array eintragen und die Anzahl der rausgelesenen Schueler speichern (return-Wert) */
    int student_count = load_students(students, test_path);
    
    /* Ausgeben der gespeicheren Informationen */
    printf("%d Schueler geladen.\n\n", student_count);
    
    for (int i = 0; i < student_count; i++) {
        printf("Name: %s\nID: %s\n\n", students[i].name, students[i].id);
    }
    
    return 0;
}


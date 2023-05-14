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

/**
 * @brief Liest eine CSV-Datei aus, in der Schuelernamen- und Kennungen gespeichert sind und speichert jeden Schueler in ein Element vom Typen student
 * @param students Ein Array aus struct students, welches grosz genug sein muss um jeden Schueler speichern zu koennen
 * @param file_path Ein String der den Pfad zur Datenbank beinhaltet
 * @return Die Anzahl der gespeicherten Studenten
*/
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
    
    fclose(student_list);
    
    return index;
}

void save_students(student students[], int student_count, char file_path[]) {
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

int main(void) {
    
    /* Unit test */
    student students[MAX_STUDENTS];
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
    
    return 0;
}
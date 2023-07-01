#include "io.hpp"

/**
 * @brief Fordert den Benutzer auf eine Auswahl zu treffen, wie stark der Saal ausgelastet werden soll. Drei Moeglichkeiten stehen zur Auswahl.
 * @return Die Auswahl des Benutzers als Typ enum Selection
*/
Selection select_layout(void) {
    printf("Sie haben die Moeglichkeit eine Auslastungsrate fuer den Hoersaal zu waehlen.\n"
            "Wird keine Auswahl getroffen, gibt es keine Einschraenkungen und es wird eine 100%% Auslastung des Hoersaals generiert.\n\n"
            "Sie koennen nun waehlen:\n"
            "1 fuer eine 25%% Auslastung.\n"
            "2 fuer eine 50%% Auslastung.\n"
            "Enter fuer eine volle Auslastung.\n"
            "Bitte waehlen: ");

    char user_input[MAX_TOKEN_LEN] = {0};
    
    fgets(user_input, MAX_TOKEN_LEN, stdin);
    while((user_input[0] > '3' || user_input[0] < '1') && user_input[0] != '\n'){
        printf("Ungueltige Eingabe.\nBitte waehlen: ");
        fgets(user_input, MAX_TOKEN_LEN, stdin);
    }

    if (user_input[0] == '1') {
        printf("Es wird nun eine Auslastungsrate von 25%% generiert.\n");
        return QUARTER;
    }
    if (user_input[0] == '2') {
        printf("Es wird nun eine Auslastungsrate von 50%% generiert.\n");
        return HALF;
    }
    
    printf("Sie haben keine Auswahl getroffen. Der Hoersaal kann komplett belegt werden.\n");
    return FULL;
}

/**
 * @brief Liest eine CSV-Datei aus, in der Schuelernamen- und Kennungen gespeichert sind und speichert jeden Schueler in ein Element vom Typen student
 * @param students Ein Array aus struct students, welches grosz genug sein muss um jeden Schueler speichern zu koennen
 * @param file_path Ein String der den Pfad zur Datenbank beinhaltet
 * @return Die Anzahl der gespeicherten Studenten
*/
int load_students(Student students[], const char* file_path) {
    
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
        
        if (index > MAX_STUDENTS) {
            fclose(student_list);
            return index;
        }
    }
    
    fclose(student_list);
    
    return index;
}

void save_students(Student students[], int student_count, const char* file_path) {
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

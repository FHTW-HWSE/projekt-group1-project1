#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#define MAX_ROWS     20
#define MAX_SEATS    20
#define MAX_STUDENTS MAX_ROWS * MAX_SEATS

#define MAX_TOKEN_LEN 100

/**
 * @brief Auswahl der gewuenschten Auslastung
*/
typedef enum{ QUATER, HALF, FULL } Selection;

typedef struct {
    char name[MAX_TOKEN_LEN];
    char id[MAX_TOKEN_LEN];
} Student;

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
            "3 fuer eine volle Auslastung.\n"
            "Bitte waehlen: ");

    int choice;
    scanf("%d", &choice);

    while(choice > 3 || choice < 1){
        printf("Ungueltige Eingabe.\nBitte waehlen: ");
        scanf("%d", &choice);
    }

    printf("Sie haben %d gewaehlt.", choice);
    if (choice == 1) {
        printf("Es wird nun eine Auslastungsrate von 25%% generiert.");
        return QUATER;
    }
    if (choice == 2) {
        printf("Es wird nun eine Auslastungsrate von 50%% generiert.");
        return HALF;
    }
    
    printf("Sie haben keine Auswahl getroffen. Der Hoersaal kann komplett belegt werden.");
    return FULL;
}

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

    printf("Geben Sie nach der Aufforderung '2' ein.\n\n");

    if(select_layout() == HALF) {
         printf("\nUnit Test bestanden.\n");
    } else {
        printf("\nEtwas ist nicht nach Plan gelaufen.\n");
    }


    printf("Geben Sie nach der Aufforderung '3' ein.\n\n");
    
    if(select_layout() == FULL) {
         printf("\nUnit Test bestanden.\n");
    } else {
        printf("\nEtwas ist nicht nach Plan gelaufen.\n");
    }

    return 0;
}



/*

//************FIND AVAILABLEE SEAT AND ASSIGNE IT TO STUDEN**************

//This function is checking int the room data what seats are still available, randomly selects one of the available seats
//and assigns the selected seat to the user data

void checkAvailableSeats(Room* room, User* users, int numUsers) {
    int availableSeats[MAX_NUM_SEATS];
    int numAvailableSeats = 0;

    // Loop through each seat in the room
    for (int i = 0; i < room->numSeats; i++) {
        int seatNum = room->seats[i];

        // Check if the seat is available
        bool isAvailable = true;
        for (int j = 0; j < numUsers; j++) {
            if (users[j].seatNum == seatNum) {
                isAvailable = false;
                break;
            }
        }

        // If the seat is available, add it to the availableSeats array
        if (isAvailable) {
            availableSeats[numAvailableSeats] = seatNum;
            numAvailableSeats++;
        }
    }

    // Randomly choose an available seat and assign it to the user
    if (numAvailableSeats > 0) {
        int randIndex = rand() % numAvailableSeats;
        int chosenSeatNumber = availableSeats[randomIndex];
         // loop to find the user with the corresponding studentID
        for (int i = 0; i < NUM_USERS; i++) {
            if (users[i].id == studentID) {
                users[i].seatNumber = chosenSeatNumber; // the user will be assigned the chosen seat
                printf("Seat %d has been assigned to student with ID %d\n", chosenSeatNumber, studentID);
                break;
        }
    }
}


//**********************FUNCTION FOR REGISTRATION************************

void registerForExam() {
  // Print request to enter student ID to console
  printf("Please enter your student ID to register for the exam:\n");
  // Use scanf to read user input
  int studentID;
  scanf("%d", &studentID);

  // Check if the entered ID is registered for the exam
  bool isRegistered = checkRegistration(studentID);
  if (!isRegistered) {
    printf("Error: Student ID %d is not registered for the exam.\n", studentID);
    return;
  }

  // Check which seats are still available in the room
  readRooms();

  // Randomly select an available seat
  int seatNumber = selectSeat();

  // Assign the selected seat to the user data
  bool isAssigned = assignSeat(studentID, seatNumber);
  if (!isAssigned) {
    printf("Error: Student ID %d is already assigned to a seat.\n", studentID);
    return;
  }

  printf("Seat assigned: Student ID %d is assigned to seat %d.\n", studentID, seatNumber);
}


//***********************************************************************
//***********************************MAIN********************************
//***********************************************************************

int main() {
    int choice;
    readRooms();
    readStudents();
    
    //Print main menue
    while (1) {
        printf("\n********** MENU **********\n");
        printf("1. Register for Exam\n");
        printf("2. Retrieve List of Neighbors\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:    //If the user selects "Register for Exam" a function is called that requests to enter the student ID is printed to the console
                registerForExam();
                break;
            case 2:
                retrieveNeighbors();
                break;
            case 3:
                printf("Quitting...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}
        */

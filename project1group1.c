//**********************************HEADER*******************************
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_ROWS     20
#define MAX_SEATS    20
#define MAX_STUDENTS MAX_ROWS * MAX_SEATS

#define MAX_TOKEN_LEN 100

typedef struct {
    char name[MAX_TOKEN_LEN];
    char id[MAX_TOKEN_LEN];
} student;

//Funktion load_students
int load_students(student students[], char file_path[]) {
    
    FILE* student_list = fopen(file_path, "r");
    if (student_list == NULL) {
        printf("Datenbank nicht gefunden.\n");
        return 0;
    }
    
    char line_buffer[100];
    int index = 0;
    
    char *token_buffer; // Speichert einen Teil vom String. 
                        // Z.B. "Eteri" aus "Eteri,123456"
    
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


//***************************FUNCTION READ FILE**************************



//**********************FUNCTION WRITE FILE TO ARRAY*********************



//**********************FUNCTION WRITE ARRAY TO FILE*********************



//********************ID AND NEIGHBOR SEARCH FUNCTION********************





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


//**********CHECK FUNCTION IF USER IS REGISTERED FOR THE EXAM************

//This function is checking if the entered ID is available in the user data
bool checkRegistration(int studentID) {
    for (int i = 0; i < numRegisteredUsers; i++) {
        if (registeredUsers[i].studentID == studentID) {
            return true; // Student is registered
        }
    }
    return false; // Student is not registered
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
        

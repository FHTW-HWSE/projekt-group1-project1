//**********************************HEADER*******************************
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>


//***************************FUNCTION READ FILE**************************



//**********************FUNCTION WRITE FILE TO ARRAY*********************



//**********************FUNCTION WRITE ARRAY TO FILE*********************



//********************ID AND NEIGHBOR SEARCH FUNCTION********************





//************FIND AVAILABLEE SEAT AND ASSIGNE IT TO STUDEN**************

//This function is checking int the room data what seats are still available.


//This Function randomly selects one of the available seats


//This Function assigns the selected seat to the user data




//**********CHECK FUNCTION IF USER IS REGISTERED FOR THE EXAM************

//This function is checking if the entered ID is available in the user data


//If the user ID exists the function returns true


//If the ID doesn't exists, the function returns false and prints an related error message to the console



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
        

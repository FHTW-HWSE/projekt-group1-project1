#include "seating.hpp"

int seat_exist(int row, int seat, Seat room[][MAX_SEATS], int rows, int seats) {
    int exist = 1;
    if (row < 0 || seat < 0 || row >= rows || seat >= seats) {
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
        for (int j = 0; j < seats; j++)
            room[i][j].available = 0;

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
        for (int j = 0; j < seats; j++)
            room[i][j].available = 0;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < seats; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 1) {
                    room[i][j].available = 1;
                }
            }
        }
}



int assign_seat(Seat room[][MAX_SEATS], int rows, int seats, Student student) {
    for (int r = 0; r < rows; r++) {
        for (int s = 0; s < seats; s++) {
            if (room[r][s].available == 1) {
                strcpy(room[r][s].student.name, student.name);
                strcpy(room[r][s].student.id, student.id);
                room[r][s].available = 0;
                printf("Sitzplatz zugewiessen: Reihe %d, Platz %d \n" , r , s );
                return 1;
            }
        }
    }
    return 0;
}

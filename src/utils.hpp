#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#define MAX_ROWS     20
#define MAX_SEATS    20
#define MAX_STUDENTS MAX_ROWS * MAX_SEATS

#define MAX_TOKEN_LEN 50

#define REMOVE_NEWLINE(a) if(strlen(a) > 0 && a[strlen(a)-1] == '\n') a[strlen(a)-1] = '\0';

/**
 * @brief Auswahl der gewuenschten Auslastung
*/
typedef enum{ QUARTER, HALF, FULL } Selection;

typedef struct {
    char name[MAX_TOKEN_LEN];
    char id[MAX_TOKEN_LEN];
} Student;

typedef struct
{
    int available;
    Student student;
} Seat;

/**
 * @brief Liest eine CSV-Datei aus, in der Schuelernamen- und Kennungen gespeichert sind und speichert jeden Schueler in ein Element vom Typen student
 * @param students Ein Array aus struct students, welches grosz genug sein muss um jeden Schueler speichern zu koennen
 * @param file_path Ein String der den Pfad zur Datenbank beinhaltet
 * @return Die Anzahl der gespeicherten Studenten
*/
int load_students(Student students[], const char* file_path);

void save_students(Student students[], int student_count, const char* file_path) ;

/**
 * @brief Fordert den Benutzer auf eine Auswahl zu treffen, wie stark der Saal ausgelastet werden soll. Drei Moeglichkeiten stehen zur Auswahl.
 * @return Die Auswahl des Benutzers als Typ enum Selection
*/
Selection select_layout(void);

int seat_exist(int row, int seat, Seat room[][MAX_SEATS], int rows, int seats);

/**
 * @brief Gets coordinates for a seat of a student and prints out all direct neighbors
 * @param row The row of the desired student
 * @param seat The seat number of the desired student
 * @param room A 2D-array consisting of the maximum possible numbers of seats and rows
 * @param rows The number of rows according to the actual size of the room in use
 * @param seats The number of seats according to the actual size of the room in use
*/
void direct_neighbours(int row, int seat, Seat room[][MAX_SEATS], int rows, int seats);

void indirect_neighbours(int row, int seat, Seat room[][MAX_SEATS], int rows, int seats);

/**
 * @brief Generiert ein Belegungsmuster fuer eine volle Auslastung des Hoersaals
 * @param room Ein 2D-Array mit dem Attribut available fuer die Verfuegbarkeit
 * @param rows Die Anzahl an Sitzreihen des Saals
 * @param seats Die Anzahl der Sitze pro Sitzreihe
*/
void fully_occupied(Seat room[][MAX_SEATS], int rows, int seats);
void half_occupied(Seat room[][MAX_SEATS], int rows, int seats);
void quarter_occupied(Seat room[][MAX_SEATS], int rows, int seats);
int assign_seat(Seat room[][MAX_SEATS], int rows, int seats, Student student);

#endif /* utils_h */

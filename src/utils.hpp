#ifndef UTILS_HPP
#define UTILS_HPP

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

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



#endif /* utils_h */

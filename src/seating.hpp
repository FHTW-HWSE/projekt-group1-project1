#ifndef SEATING_HPP
#define SEATING_HPP

#include "utils.hpp"

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

#endif
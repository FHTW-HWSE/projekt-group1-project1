#ifndef IO_HPP
#define IP_HPP

#include "utils.hpp"
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

#endif
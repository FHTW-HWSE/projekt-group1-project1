#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "project1group1.h"

int main(void) {
    
    Seat class[MAX_ROWS][MAX_SEATS]; 
    char user_input[MAX_TOKEN_LEN];
    int rows = 0;
    int seats = 0;

    printf("Servus! Dies ist eine Hilfestellung fuer die Belegung Ihres Klassenraumes.\n"
        "Wenn es gerade nicht moeglich ist den Klassenraum vollstaendig zu fuellen,\n" 
        "helfen wir Ihnen gerne eine passene Belegungsrate sowie einen angemessenen Sitzplan zu generieren.\n"
        "Mithilfe Ihren Angaben wird ein passendes Model erstellt.\n"
        "Bitte geben Sie an wieviele Sitzreihen es in Ihrem Hoersaal gibt:\n");
    fgets(user_input,MAX_TOKEN_LEN,stdin);
    rows = atoi(user_input);
    printf("Bitte geben Sie an wieviele Sitze es pro Reihe gibt:\n\n");
    fgets(user_input,MAX_TOKEN_LEN,stdin);
    seats = atoi(user_input);// Schleife mit Error fehlt noch
    
    Selection selection = select_layout();



    return 0;
}


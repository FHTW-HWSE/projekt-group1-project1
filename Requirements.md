Requirements:

Es wird ein User Interface implementiert:
    Das Menü fragt ab ob ein Hörsall generiert werden soll oder ob die Nachbarabfragung stattfinden soll.
    Es gibt eine Benutzeroberfläche die einfach und schnell die gewünschten Optionen anzeigt. Man kann entweder den Hörsaal generieren lassen mit den passenden Anforderungen des Belegungsmusters, wie auch 
    der Speicherung der Studentendaten wie Name und Sitzplatzvergabe. Andererseits kann man bei Erkrakung eines Studenten die Sitznachbarn abfragen.

Auswahl der Hörsaalgenerierung:
    Examerstellung mit Speicherung der dazugehörigen Daten:
    Es wird der Name des Exams abgefragt die Uhrzeit und das Datum.
    
Generieren des ausgewählten Belegungsmusters bei Angabe von Reihen und Spalten des Hörsaals: 
    Es wird die Auslegungsrate abgefragt, 100%, 50%, oder 25%.
    Das Belegungsmuster und die Sitzplatzvergabe wird dem Hörsaal, bei Angabe von der Anzahl an Reihen und Spalten angepasst und generiert.

Vergabe des Sitzplatzes bei Eingabe einer Studierendenkennung: 
   Je nach Belegungsmuster werden dann die passende Anzahl an Sitzplätzen generiert und bei Eingabe der Studenteneigenschaften der nächste frei Platz mit einer Nummer ausgegeben.

Abspeichern der Studierendenkennung und des Sitzplatzes: 
   Die Daten des Studenten werden darauf folgend dem Sitzplatz zugewiesen, was in einer Datenbank gespeichert wird.

Auswahl der Abfrage der Sitznachbarn eines erkrankten Studenten:
  Abfragen der direkten Nachbarn eines bestimmten Studierenden, abfragen der indirekten Nachbarn eines bestimmten Studierenden. 
   Wird ein Student krank und man muss nun die Nachbarn eruieren, kann man nach Eingabe der Studenteneigenschaften die direkten und indirekten Nachbarn abfragen, die in einer CSV Datei abgespeichert wurden.
 

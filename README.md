# projekt-group1-project1
projekt-group1-project1 created by GitHub Classroom

**Sitzverwaltungssystem**

Dieses Programm ermöglicht das Erstellen und Verwalten von Sitzplatzanordnungen für Prüfungen. Es bietet zwei Hauptfunktionen:

Erstellen einer neuen Prüfung und Sitzplatzanordnung.
Abfragen der Sitznachbarn eines bestimmten Studierenden.
Voraussetzungen
Bevor Sie dieses Programm verwenden können, stellen Sie sicher, dass Folgendes installiert ist:

C-Compiler (z. B. GCC)

In den build-Ordner ein Terminal öffnen und folgende Befehle ausführen
cmake ..
make 
danach befinden sich im build-Ordner eine test_app mit den unit tests und eine release_app

**Neue Prüfung erstellen:** Mit dieser Option können Sie eine neue Prüfung erstellen und eine Sitzplatzanordnung einrichten.

**Sitznachbarn abfragen:** Mit dieser Option können Sie die Sitznachbarn eines bestimmten Studierenden abfragen.

Option 1: Neue Prüfung erstellen
Geben Sie 1 ein und drücken Sie die Eingabetaste.
Geben Sie die folgenden Informationen zur Prüfung ein:
Datum (JJJJMMTT): Geben Sie das Prüfungsdatum im Format JJJJMMTT ein.
Uhrzeit (HHMM): Geben Sie die Prüfungszeit im Format HHMM ein.
Raumnummer: Geben Sie die Raumnummer ein, in der die Prüfung stattfindet.
Name: Geben Sie den Namen der Prüfung ein.

Geben Sie anschließend die Anzahl der Sitzreihen im Raum und die Anzahl der Sitze pro Reihe an.

Wählen Sie eine Option für die Sitzplatzanordnung:
VOLL: Alle Sitze im Raum werden besetzt sein.
HALB: Nur die Hälfte der Sitze im Raum wird besetzt sein.
VIERTEL: Nur ein Viertel der Sitze im Raum wird besetzt sein.
Das Programm generiert eine eindeutige Prüfungs-ID und zeigt sie an. Diese ID wird für zukünftige Abfragen benötigt.
Das Programm erstellt zwei Dateien:
Eine CSV-Datei ([test_id].csv) mit den Prüfungsdetails.
Eine Studentendatei ([test_id]S.csv) mit den Namen und IDs der Studierenden.
Option 2: Sitznachbarn abfragen
Geben Sie 2 ein und drücken Sie die Eingabetaste.
Geben Sie die Prüfungs-ID der Prüfung ein, die Sie abfragen möchten. Stellen Sie sicher, dass Sie die Dateierweiterung .csv angeben.
Das Programm lädt die Sitzplatzanordnung für die angegebene Prüfung.
Es zeigt die Liste der an der Prüfung teilnehmenden Studierenden an.
Geben Sie den Namen eines Studenten ein.um die Sitznachbarn abzufragen.

Wenn eine Übereinstimmung gefunden wird, zeigt das Programm die direkten und indirekten Sitznachbarn des angegebenen Studierenden an.
Wenn keine Übereinstimmung gefunden wird, zeigt das Programm an, dass kein Studierender mit dem angegebenen Namen gefunden wurde.
Einschränkungen
Die maximale Anzahl der Reihen (MAX_ROWS) und Sitze pro Reihe (MAX_SEATS) ist vordefiniert und muss möglicherweise für größere Sitzplatzanordnungen angepasst werden.
Das Programm geht davon aus, dass der Benutzer korrekte und gültige Eingaben macht. Ungültige Eingaben können zu unerwartetem Verhalten oder Fehlern führen.
Mitarbeit
Beiträge zum Sitzverwaltungssystem sind willkommen. Wenn Sie auf Probleme stoßen oder Vorschläge zur Verbesserung haben, erstellen Sie bitte ein neues Issue oder reichen Sie einen Pull Request ein.

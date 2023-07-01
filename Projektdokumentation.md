HWSE 2
Gruppenprojekt 1    

Projektteam Gruppe 1:
Eteri Cholokava,
Karin Lang,
Samin Aghaeihajiagha,  

Verzeichnis:

I........Aufgabenstellung

II.......Requirements

III......USER STORIES

IV........Projektdokumentation

**************************************************************************************************************************************************************************************************************

I. Aufgabenstellung 

Auch in Zeiten der Pandemie ist es leider nicht immer möglich, alle Prüfungen als Online- 
Prüfung abzuhalten. Da auch in kommenden Zeiten ein Auftreten von Krankheitswellen zu erwarten 
ist, muss ein Programm entwickelt werden, mit dem die Sitznachbarn eines Studierenden 
ermittelt werden können. Um Zukunftssicher zu sein, müssen die direkten und indirekten 
Sitznachbarn ermittelt werden können. Eine grafische Erläuterung der direkten und indirekten 
Sitznachbarn ist in Abbildung 1 ersichtlich. Das Programm muss mit verschiedenen Belegungsmustern 
ausgestattet sein. Die möglichen Belegungsmuster sind in den Abbildungen 2–4 
ersichtlich. Bitte beachten Sie, dass das Belegungsmuster in Abbildung 2 für eine Zeit nach der 
Pandemie vorgesehen ist. 

Folgende Aufgaben muss das Programm erfüllen: 

    • Es muss ein User Interface implementiert werden. 
    • Generieren des ausgewählten Belegungsmusters bei Angabe von   Reihen und Spalten des Hörsaals. 
    • Vergabe des Sitzplatzes bei Eingabe einer Studierendenkennung. 
    • Abspeichern der Studierendenkennung und des Sitzplatzes. 
    • Abfragen der direkten Nachbarn eines bestimmten Studierenden. 
    • Abfragen der indirekten Nachbarn eines bestimmten Studierenden. 
    
**************************************************************************************************************************************************************************************************************

II. Requirements:

Es wird ein User Interface implementiert:
    Das Menü fragt ab ob ein Hörsall generiert werden soll oder ob die Nachbarabfragung stattfinden soll.
    Es gibt eine Benutzeroberfläche die einfach und schnell die gewünschten Optionen anzeigt. 
    Man kann entweder den Hörsaal generieren lassen mit den passenden Anforderungen des Belegungsmusters, wie auch 
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
   Wird ein Student krank und man muss nun die Nachbarn eruieren, kann man nach Eingabe der Studenteneigenschaften die direkten und indirekten Nachbarn abfragen, 
   die in einer CSV Datei abgespeichert wurden.

Nicht-Funktionale Requirements:
    Es wird gibt ein benützerfreundliches User Interface, das den Benützer narrensicher durch das Programm leitet.
    Es werden 2 CSV Dateien erstellt. Die 1. CSV Datei um die Prüfungen abzuspeichern mit den dazugehörigen Eigenschaften und die 2. CSV        Datei enthält die Studentendaten und die Sitzplätze.
    Die Verzeichnisse der CSV Dateien könne gelesen werden damit dem Benützer mit einfacher Eingabe die Sitznachbarn ausgeben werden können.

**************************************************************************************************************************************************************************************************************

III. User Story:

Benützer will ein neues Exam erstellen (Name, Datum, Uhrzeit, Raumnummer) um einen Hörsaal mit passender Größe zu generieren um die Sitznachbarn der Studenten abzufragen.


Given: Benützer startet Programm

When:  ein neues Exam stattfindet

Then:  Benützer wird aufgefordert ein neues Exam zu erstellen oder eine Sitznachbarabfrage stattfinden soll<br>


Given: Benützer will neues Exam starten

When:  ein neues Exam stattfindet

Then:  Benützer wird aufgefordert Exameigenschaften einzugeben


Given: Benützer will Exam speichern

When:  Exameigenschaften eingegeben wurden

Then:  werden Exameigenschaften in einer CSV Datei mit einer eigenen ID abgespeichert und diese ID wird ausgegeben


Given: Benützer will die Auslastung zu einem Hörsaal generieren

When:  ein neues Eam erstellt wurde

Then:  Aufforderung an den Benützer die gewünschte Auslastung anzugeben


Given: Aufforderung an den Benützer die Spalten und Rehen anzugeben

When:  Auslastung angegeben wurde

Then:  werden Anzahl der Spalten und Reihen angegeben


Given: Student benütigt einen Sitzplatz

When:  Auslastung und Größe generiert wurde

Then:  wird der nächste freie Sitzplatz angezeigt, sofern einer existiert


Given: Student wird auf diesem Sitzplatz gespeichert

When:  Student an diesem Exam teilnimmt

Then:  wird der Student mit dem dazugehörigen Sitzplatz in einer CSV Datei gespeichert


Given: Benützer will die direkten und indirekten Sitznachbarn eines erkrankten Studenten abfragen

When:  Student sich krank meldet

Then:  wird im Menü Sitznachbarausgabe gewählt


Given: Exam ID wird angegeben um die Sitznachbarn abzufragen

When:  Benützer benötigt eine Liste der Studenten die an Examen teilgenommen haben

Then:  Liste wird ausgegeben


Given: Liste an Sitznachbarn soll eroiert werden

When:  Sitznachbarn werden gesucht

Then:  Sitznachbarn werden in der Konsole ausgegeben.


**************************************************************************************************************************************************************************************************************

IV. Projektdokumentation
Projektname: Projekt1Gruppe1
Projektmitglieder: Eteri Cholokava, Karin Lang, Samin Aghaeihajiagha

Vorarbeit des Projekts:
Nachdem das Projekt ausgewählt wurde, haben wir die Anforderungen und User Stories erstellt. In den User Stories haben wir die Anforderungen für das Projekt diskutiert und darüber gesprochen, wie wir sie umsetzen können. Wir haben die einzelnen User Stories mithilfe der Given-When-Then-Logik bearbeitet und unterteilt, um die Aufgaben klar zu definieren und eine Vorgehensweise zu entwickeln.
Wir haben Zoom-Meetings abgehalten, um alle Details mit den Kollegen abzustimmen. Schritt für Schritt haben wir die User Stories angepasst. Anfangs hatten wir einige zusätzliche Funktionen eingebaut, die das Programm unnötig komplex gemacht hätten. Nach einer kurzen Überlegung sind wir zu dem Schluss gekommen, dass in einer freien Marktwirtschaft das geliefert werden sollte, was der Kunde gefordert hat - nicht mehr und nicht weniger. Daher haben wir uns darauf geeinigt, uns konkret auf die einzelnen Anforderungen zu konzentrieren und keine Extras zu implementieren. Dadurch wurden einige Funktionen gestrichen, die nicht Teil der Anforderungen waren.
Um das Programm gemäß den Anforderungen zu entwickeln, haben wir mithilfe der User Stories Issues erstellt. Wir haben Git verwendet, um das Projekt gemeinsam zu bearbeiten. Die Issues wurden aufgeteilt und in kleinere Abschnitte unterteilt. Dadurch erhielten wir einen genaueren Überblick über das Projekt und konnten entsprechende Aufgaben jedem einzelnen Projektmitarbeiter zuweisen.

Hauptteil:
Wir haben damit begonnen, die grundlegenden Funktionen zu implementieren, die für die Eigenschaften der Programmattribute erforderlich waren. Wir haben Funktionen erstellt, mit denen CSV-Dateien erstellt, gelesen und bearbeitet werden können, um Eigenschaften wie Studenten, Sitzplätze und Prüfungsdaten zu verwalten. Sobald die Funktionalität dieser Grundfunktionen nachgewiesen war, konnten wir darauf aufbauend weitere Features implementieren. Dazu gehörte ein benutzerfreundliches User Interface mit einem intuitiven Menü, das von jedem Benutzer problemlos genutzt werden konnte. Wir haben auch eine Funktion eingebaut, die für jeden möglichen Hörsaal ein passendes Auslastungsmuster generieren konnte, basierend auf den angegebenen Daten zur Anzahl der Reihen und Spalten. Jeder Student erhielt einen Sitzplatz, der in einer separaten CSV-Datei gespeichert wurde, falls ein Student krank wurde. In dieser Datei wurden die Namen der Studenten zusammen mit ihren Matrikelnummern gespeichert. Anschließend haben wir daran gearbeitet, dass im Falle einer Krankmeldung eines Studenten die direkten und indirekten Sitznachbarn in der Konsole angezeigt werden können. Eine Prüfung bestand aus zwei CSV-Dateien. Wir haben dafür gesorgt, dass in einer Datei mit der Endung "-T.csv" Prüfungseigenschaften wie Datum, Uhrzeit, Raumnummer und Name der Prüfung sowie wichtige Informationen zur Rekonstruktion der Sitzplatzbelegung (Größe und Auslastung des Raums) gespeichert wurden. In der anderen Datei mit der Endung "-S.csv" wurden die Namen der Studenten und ihre Matrikelnummern gespeichert wurden. Es gab einige Unstimmigkeiten, als wir versuchten, die Dateien miteinander zu verknüpfen, um die Sitznachbarn auszugeben. Glücklicherweise konnten wir das Problem schnell lösen, da es sich nur um einen Formatfehler handelte. Die Suche nach diesem Fehler gestaltete sich jedoch etwas schwierig, da der Compiler ihn nicht als Fehler anzeigte. Der Fehler trat nur auf, wenn bestimmte Funktionen im Programm übersprungen wurden und führte zu einem Segmentation Fault. Durch die Verwendung von printf konnten wir den Fehler aufspüren. Anschließend konnten die Studenten in der Konsole ausgegeben werden, nachdem die Studentenerkennung bei der Abfrage eingegeben wurde.

Abschluss:
Letztendlich war es eine spannende und praxisnahe Aufgabe, die wir als Team erfolgreich gemeistert haben.



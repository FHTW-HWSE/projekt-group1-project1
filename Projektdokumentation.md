HWSE 2
Gruppenprojekt 1

Projektteam Gruppe 1:
Eteri Cholokava
Karin Lang
Samin Aghaeihajiagha

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
    Es werden 2 CSV Dateien erstellt. Die 1. CSV Datei um die Prüfungen abzuspeichern mit den dazugehörigen Eigenschaften und die 2. CSV Datei enthält die Studentendaten und die Sitzplätze.
    Die Verzeichnisse der CSV Dateien könne gelesen werden damit dem Benützer mit einfacher Eingabe die Sitznachbarn ausgeben werden können.

**************************************************************************************************************************************************************************************************************

III. User Story:

Benützer will ein neues Exam erstellen (Name, Datum, Uhrzeit, Raumnummer) um einen Hörsaal mit passender Größe zu generieren um die Sitznachbarn der Studenten abzufragen.

Given: Benützer startet Programm
When:  ein neues Exam stattfindet
Then:  Benützer wird aufgefordert ein neues Exam zu erstellen oder eine Sitznachbarabfrage stattfinden soll

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
Nachdem das Projekt gewählt wurde, wurden die Requirements und UserStorys erstellt. 
In den UserStorys wurde besprochen welche Anforderungen an das Projekt gestellt wurden und wie wir diese verwirklichen können. 
Mit Hilfe der Given, Then, When Logik wurden die einzelnen UserStorys bearbeitet und unterteilt. Dadurch konnten die einzelnen Aufgaben eingeschränkt werden und eine Vorgehensweise erstellt werden.
Es gab Zoom Meetings um alle Details zu mit den Kollegen abzusprechen. Nach und nach wurden die UserStorys angepasst. Anfangs hatten wir einige 
Extrafeatures eingebaut, die das Programm sehr stark vergrößert hätte. Nach einer kurzen Besinnung kamen wir zu dem Resultat, dass in der freie Marktwirtschaft 
das geliefert wird was der Kunde gefordert hat. Nicht mehr nicht weniger. Daher einigten wir uns darauf, dass konkret auf die einzelnenn Requirements eingegeangen wird und keine Extras implementiret werden. 
Daher wurden Features gestrichen, da sie nicht Teil der Anforderung waren. 
Um das Programm den Anforderungen entsprechend zu schreiben wurden dann mithilfe der UserStorys die Issues erstellt. Mithilfe von Git konnten wir das Projekt gemeinsam bearbeiten.
Die Issues wurden aufgeteilt und in kleiner Sektionen unterteilt. Dadurch bekamen wir eine genauere Übersicht über das Projekt und konnten entsprechende Funktionen jedem einzelnen Projektmitarbeiter zuweisen.


# 🏦 Banksimulator

Dieses Projekt implementiert einen **kompletten Banksimulator** mit grundlegenden Funktionen zur **Kunden- und Kontoverwaltung**, inkl. Rechteverwaltung und Währungsumrechnung.

##  Funktionen

### 👤 Kundenverwaltung
- Anlegen neuer Kunden (`_AddNew`)  
- Löschen von Kunden (`Delete`)  
- Abfragen des Kontostands (`getAccountBalance`)  
- Umsetzung in der Klasse **`clsBankClient`**

### 💳 Banktransaktionen
- Einzahlungen  
- Auszahlungen  
- Überweisungen  
- Implementiert innerhalb von **`clsBankClient`**

### 🔑 Benutzer- und Rechteverwaltung
- Verwaltung von Systemnutzern über **`clsUser`**  
- Zugriffskontrolle mittels `CheckAccesRights` und Rechten wie *eAll* oder *pListClients*  
- ⚠️ Hinweis: Es existiert aktuell **nur ein Login für Systemnutzer**, eine separate Client-Anmeldung ist nicht vorhanden

### 🛠️ Eigene Hilfsbibliotheken
- String-Operationen und Datumsfunktionen über selbst entwickelte Klassen im Verzeichnis **`utils/`**

### 💱 Währungswechsel / Wechselgeld-Funktion
- Realisiert durch eine **Currency-Klasse** mit Umrechnungslogik  
- Eigener **Rechner-Bildschirm** zur einfachen Umrechnung von Währungen

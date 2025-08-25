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
- Es existiert aktuell **ein Login für Systemnutzer**.
### 🛠️ Eigene Hilfsbibliotheken
- String-Operationen und Datumsfunktionen über selbst entwickelte Klassen im Verzeichnis **`utils/`**

### 💱 Währungswechsel / Wechselgeld-Funktion
- Realisiert durch eine **Currency-Klasse** mit Umrechnungslogik  
- Eigener **Rechner-Bildschirm** zur einfachen Umrechnung von Währungen
  
## 📌 To-Do Liste

### ✅ Bereits erledigt
- [x] Kundenverwaltung implementiert (`clsBankClient`)  
- [x] Transaktionen (Einzahlung, Auszahlung, Überweisung) integriert  
- [x] Benutzer- und Rechteverwaltung umgesetzt (`clsUser`, `CheckAccesRights`)  
- [x] Eigene Utility-Bibliotheken für String- und Datumsfunktionen erstellt  
- [x] Währungswechsel und Wechselgeld-Rechner hinzugefügt

### 🔜 Nächste Schritte
- [ ] Code-Organisation verbessern (bessere Projekt- und Ordnerstruktur)  
- [ ] Code-Refactoring zur Steigerung von Übersichtlichkeit und Wartbarkeit  
- [ ] Datenbankintegration (Ersetzen des Dateisystems (File-System) durch eine "RDBMS" relationale Datenbank, z.B.: MySQL oder MSSQL)  
- [ ] Erweiterung der Benutzeroberfläche (separates Login für Admins und Clients) 

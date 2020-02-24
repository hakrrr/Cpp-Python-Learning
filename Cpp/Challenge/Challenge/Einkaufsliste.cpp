#include <forward_list>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <regex>

#define erfassen(B, M, K) RL.push_front(Rechnung(IdC++, B, M, K))
#define entf(ID) RL.remove_if([&ID](const Rechnung& r) {return r.Id == ID; })
#define FOR(x, i) for(int i = 0; i < x; ++i)
#define FORR(it, l) for(auto it = l.begin(); it != l.end(); ++it)

using namespace std;

struct Rechnung {
	int Id, Betrag;
	string Monat, Kategorie;

	Rechnung(int a, int b, string c, string d) {
		Id = a, Betrag = b, Monat = c, Kategorie = d;
	}
};

string months[12] = {"Januar", "Februar", "Maerz", "April", "Mai", "Juni", "Juli", "August",
					"September", "Oktober", "November", "Dezember"};
string categories[8] = { "A", "B", "C", "D", "E", "F", "G", "H" };
//string _n = "____________________________________________________";
regex reg;
forward_list<Rechnung> RL;
unsigned int IdC = 1;

void init() {
	string s = "\\d+\\s(";
	FOR(12, i) s.append(months[i] + (i < 11 ? "||" : ")\\s("));
	FOR(8, i) s.append(categories[i] + (i < 7 ? "||" : ")"));
	reg = regex(s);
}

//void ausgeben() {
//	//m[Monate][Kategorie] speichert die Preise pro monat pro kategorie
//	map<string, map<string, int>> m;
//
//	FORR(it, RL) m[it->Monat][it->Kategorie] += it->Betrag;
//	cout << "Die Ausgaben (nach Monaten sortiert) sind:\n" + _n << endl;
//
//	//Iteration über m; Ausgabe bei jede Ausgabe > 0$
//	FOR(12, x) {
//		int summe = 0;
//		cout << months[x] + ": "<< endl;
//		FOR(8, y) {
//			if (m[months[x]][categories[y]])
//				cout << categories[y] + ": " << m[months[x]][categories[y]] << "$"<< endl;
//			summe += m[months[x]][categories[y]];
//		}
//		cout << "Gesamt: " << summe << "$\n" << ((summe > 500) ? "Zuviel ausgegeben!\n" : "") <<_n + "\n"<< endl;
//	}
//}

void summe() {
	map<string, int> m;
	FORR(it, RL) m[it->Kategorie] += it->Betrag;
	cout << "Summe der Ausgaben nach Kategorien sortiert: " << endl;
	FOR(8, i) cout << categories[i] + ": " << m[categories[i]] << ((i < 7) ? "$ " : "$\n");
}

//int main()
//{
//	string in;
//	cout << "Program gestartet!" << endl;
//	init();
//	while (1) {
//		cout << "Bitte geben Sie einen Befehl (Dokumentation) ein: " << endl;
//		getline(cin, in);
//
//		if (in == "ausgeben") ausgeben();
//
//		else if (in == "summe") summe();
//
//		else if (in == "ende") break;
//
//		else if (in == "erfassen") {
//			cout << "Geben Sie die Rechnung ein im Format: [Betrag] [Monat] [Kategorie]" << endl;
//			getline(cin, in);
//			if (regex_match(in, reg)) {
//				stringstream ss(in); int B; string M, K;
//				ss >> B >> M >> K;
//				erfassen(B, M, K);
//				cout << "Rechnung erfolgreich erfasst! ID: " << IdC - 1 << endl;
//			}
//			else cout << "Ungueltige Eingabe(Format||Rechtschreibung)!" << endl;
//		}
//
//		else if (in == "entfernen") {
//			cout << "Welche Rechnung möchten Sie entfernen?: ID der Rechnung" << endl;
//			getline(cin, in);
//			if (regex_match(in, regex("\\d+"))) {
//				int ID = stoi(in); entf(ID);
//				cout << "Erfolgreich entfernt!" << endl;
//			}
//			else cout << "Ungueltige ID!" << endl;
//		}
//
//		else if (in == "loeschen") 
//			RL.clear(), cout << "Bisher erfassten Rechnungen geloescht!" << endl;
//
//		else cout << "Ungueltiger Befehl!" << endl;
//	}
//	cout << "Program terminiert!" << endl;
//}
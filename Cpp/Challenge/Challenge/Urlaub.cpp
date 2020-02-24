#include <forward_list>
#include <string>
#include <iostream>
#include <algorithm>

#define anlg(N, V, B, Y) FL.push_front(Mitarbeiter(N, V, B, Y))
#define suche(N, V) (find_if(FL.begin(), FL.end(), [&N, &V](const Mitarbeiter& m) { return m.name == N && m.vorname == V; }))
#define entf(N, V) FL.remove_if([&N, &V](const Mitarbeiter& m) {return m.name == N && m.vorname == V; })
#define ul(Y) ((currYear - 1 - Y) < 50 ? 30 : 32)
#define FOR(it, s) for(int it = 0; it < s; ++it)
#define FORR(it, l) for(auto it = l.begin(); it != l.end(); ++it)


using namespace std;

struct Mitarbeiter {
	int urlaub = 0, byear;
	string name, vorname, bday;
	Mitarbeiter(string n, string v, string b, int y) {
		name = n, vorname = v, bday = b, byear = y;
	}
};

forward_list<Mitarbeiter> FL;
string _n = "____________________________________________________";
int size = 0;
const int currYear = 2020;

void ausgabe(forward_list<Mitarbeiter>::iterator it) {
	cout << "Name: " + it->name + "\n" << "Vorname: " + it->vorname << endl;
	cout << "Geburtstag: " + it->bday << endl;
	cout << "Resturlaub: " << ul(it->byear) - it->urlaub << "\n" + _n + "\n"<< endl;
}

void ausgeben() {
	cout << "Mitarbeiter-Liste:" << endl;
	FORR(it, FL) ausgabe(it);
}

void eingabe() {
	string n, v;
	cout << "Wer moechte Urlaub nehmen: [Name] [Vorname]" << endl; cin >> n >> v;
	auto it = suche(n, v);
	if (it != FL.end()) {
		int rUrlaub = ul(it->byear) - it->urlaub, urlaub;
		cout << "Wieviele Tage Urlaub? (Resturlaub: " << rUrlaub << ")\n"; cin >> urlaub;
		if (urlaub < rUrlaub) {
			it->urlaub += urlaub;
			cout << "Erfolgreiche gespeichert! (Resturlaub: " << ul(it->byear) - it->urlaub << ")\n";
		}
		else cout << "Ungueltige Eingabe! " << endl;
	}
}


int main() {
	anlg("James", "Li", "28.02.1998", 1998);
	ausgeben();
	eingabe();
}
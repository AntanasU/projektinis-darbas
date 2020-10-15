#include"is_failo.h"

void ne_is_failo() {
	vector<studentas> grupe;
	studentas stud;
	string pasirinkimas;
	cout << "iveskite studentu skaiciu: ";
	int n;
	cin >> n;
	while (cin.fail()) {
		cout << "klaida, iveskite skaiciu  ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> n;
	}
	string ivestis = "";
	cout << "norint skaiciuoti galutini pazymi su vidurkiu spauskite 0, jei su mediana bet kuri kita mygtuma: ";
	cin >> ivestis;
	grupe.reserve(n);
	for (int i = 0; i < n; i++) {
		stud.nd.reserve(20);
		cout << "Iveskite " << i + 1 << "-aji varda: ";
		cin >> stud.Vard;
		cout << "pavarde: ";
		cin >> stud.Pav;
		string generuoja;
		cout << "jei norite ivesti pazymius pats spauskite 0 , jei nenorite spauskite bet kuri kita mygtuka  ";
		cin >> generuoja;
		if (generuoja != "0") {
			cout << "egzamino pazimys: ";
			stud.egz = 1 + rand() % 10;
			cout << stud.egz << "\n";
			string x = "x";
			cout << i + 1 << "-ojo studento nd pazymiai, kai noresite sustoti, irasykite 0: \n";

			while (x != "0") {
				int a = 1 + rand() % 10;
				cout << a << "		";
				stud.nd.push_back(a);
				cin >> x;
			}
		}
		else {
			cout << "egzamino pazimys: ";
			int egzaminas;
			cin >> egzaminas;
			while (cin.fail() || egzaminas < 1 || egzaminas>10) {
				cout << "klaida, iveskite skaiciu ne didesni uz 10  ";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> egzaminas;
			}
			stud.egz = egzaminas;
			cout << i + 1 << "-ojo studento nd pazymiai, kai noresite sustoti, irasykite 0: \n";
			int x = -1;
			cin >> x;
			while (cin.fail() || x < 0 || x>10) {
				cout << "klaida, iveskite teigiama skaiciu, mazesni uz 10 (arba 0) ";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> x;
			}
			while (x != 0) {
				stud.nd.push_back(x);
				cin >> x;
				while (cin.fail() || x < 0 || x>10) {
					cout << "klaida, iveskite teigiama skaiciu, mazesni uz 10 (arba 0) ";
					cin.clear();
					cin.ignore(256, '\n');
					cin >> x;
				}
			}
		}
		sort(stud.nd.begin(), stud.nd.end());
		int c;
		c = stud.nd.size();
		if (ivestis != "0") {
			float mediana;
			if (c != 0) {
				if (c % 2 != 0)	mediana = stud.nd[c / 2 + 0.5];
				else    			mediana = ((float)stud.nd[c / 2 - 1] + (float)stud.nd[c / 2]) / 2;
			}
			stud.GP = mediana * 0.4 + 0.6 * stud.egz;
		}
		else {
			if (c == 0) stud.GP = 0.6 * stud.egz;
			else {
				float suma = 0;
				suma = accumulate(stud.nd.begin(), stud.nd.end(), 0);
				float vid = suma / c;
				stud.GP = vid * 0.4 + 0.6 * stud.egz;
			}
		}

		grupe.push_back(stud);
		stud.nd.clear();
	}
	isvedimas(grupe, ivestis);
}
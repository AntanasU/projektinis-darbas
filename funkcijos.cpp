#include"funkcijos.h"

bool Tvarkymas(const studentas& pirmas, const studentas& antras) {
	return pirmas.Vard < antras.Vard;
}
void isvedimas(vector<studentas> a, string ivestis) {
	cout << left << setw(20) << "Vardas " << setw(20) << "Pavarde"
		<< setw(20) << "Galutinis (vid) " << setw(20) << "Galutinis (med)";
	cout << "\n-------------------------------------------------------------------------------\n";

	{
		for (auto& d : a) {
			cout << left << setw(20) << d.Vard << setw(20) << d.Pav;
			if (ivestis == "0")	cout << setw(20) << setprecision(2) << fixed << d.GP << "----\n";
			else  cout << setw(20) << "----" << setw(20) << setprecision(2) << fixed << d.GP << "\n";
		}
	}
	a.clear();
};

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

void is_failo(string failo_pav) {
	vector<studentas> grupe;
	studentas stud;
	string pav = "";
	string vardai, pavardes, temp, egzaminas;
	vector<string> nd;
	int m;
	ifstream file(failo_pav);
	try {
		if (!file.good()) {
			throw failo_pav;
		}
		string ivestis = "";
		cout << "norint skaiciuoti galutini pazymi su vidurkiu spauskite 0, jei su mediana bet kuri kita mygtuma: ";
		cin >> ivestis;
			file >> vardai >> pavardes >> temp;
			while (temp != "Egz.") {
				nd.push_back(temp);
				file >> temp;
			}
			egzaminas = temp;
			m = nd.size();
			stud.nd.reserve(m);
			while (!file.eof()) {
				studentas stud;
				file >> stud.Vard >> stud.Pav;
				double studpaz;
				for (int i = 0; i < m; i++) {
					file >> studpaz;
					stud.nd.push_back(studpaz);
				}
				file >> stud.egz;
				if (ivestis != "0") {
					if (m != 0) {
						if (m % 2 == 1)
							stud.GP = 0.4 * stud.nd[m / 2] + 0.6 * stud.egz;
						else
							stud.GP = (stud.nd[m / 2 - 1] + stud.nd[m / 2]) / 2 * 0.4 + 0.6 * stud.egz;
					}
				}
				else {
					if (m == 0) {
						stud.GP = stud.egz * 0.6;
					}
					else {
						float bendras = 0;
						bendras = accumulate(stud.nd.begin(), stud.nd.end(), 0);
						stud.GP = bendras / m;
						stud.GP = stud.GP * 0.4 + 0.6 * stud.egz;
					}
				}
				grupe.reserve(grupe.capacity() + 1);
				grupe.push_back(stud);
				stud.nd.clear();
			}
		sort(grupe.begin(), grupe.end(), Tvarkymas);
		isvedimas(grupe, ivestis);
		}

	catch (string pav) {
		cout << pav << " failas nerastas arba negalima atidaryti \n";
	}
}

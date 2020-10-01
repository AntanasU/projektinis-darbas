#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<random>
#include <numeric>      
#include <fstream>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::setw;
using std::setprecision;
using std::fixed;
using std::rand;
using std::left;
using std::ifstream;

struct studentas {
	string Vard = "", Pav = "", ivestis = "";
	int  egz;
	vector<int>nd;
	float GP = 0, med;
};

bool Tvarkymas(const studentas& pirmas, const studentas& antras) {
	return pirmas.Vard < antras.Vard;
}

int main()
{
	vector<studentas> grupe;
	studentas stud;
	string pasirinkimas;
	cout << "jei norite skaityti duomenis is failo spauskite 0, jei ne bet kuri kita mygtuka:  ";
	cin >> pasirinkimas;
	if (pasirinkimas != "0") {
		cout << "iveskite studentu skaiciu: ";
		int n;
		cin >> n;
		while (cin.fail()) {
			cout << "klaida, iveskite skaiciu  ";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> n;
		}
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
				int x = 1;
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
			std::sort(stud.nd.begin(), stud.nd.end());
			int c;
			c = stud.nd.size();
			float mediana;
			if (c != 0) {
				if (c % 2 != 0)	mediana = stud.nd[c / 2 + 0.5];
				else    			mediana = ((float)stud.nd[c / 2 - 1] + (float)stud.nd[c / 2]) / 2;
			}
			stud.med = mediana * 0.4 + 0.6 * stud.egz;
			if (c == 0) stud.GP = 0.6 * stud.egz;
			else {
				float suma = 0;
				suma = accumulate(stud.nd.begin(), stud.nd.end(), 0);
				float vid = suma / c;
				stud.GP = vid * 0.4 + 0.6 * stud.egz;
			}
			cout << "\n Jei noresite gauti galutini pazymi pagal vidurki spauskite: 0 \n jei pagal mediana: bet ka kita \n";
			string ivestis;
			cin >> ivestis;
			stud.ivestis = ivestis;

			grupe.push_back(stud);
			stud.nd.clear();
		}
		cout << std::left << setw(20) << "vardas" << setw(20) << "pavarde" << "galutinis          mediana \n";
		cout << "-------------------------------------------------------------------\n";
		for (auto& tt : grupe) {
			cout << setw(20) << tt.Vard << setw(20) << tt.Pav;

			if (tt.ivestis != "0") {
				if (tt.nd.size() != 0)
					cout << setw(20) << "----" << setw(20) << setprecision(2) << fixed << tt.med << "\n";
				else
					cout << setw(20) << "----" << setw(20) << "nera" << "\n";
			}
			else 	cout << setw(20) << setprecision(2) << fixed << tt.GP << setw(20) << "----" << "\n";
		}
	}
	else {
	string pav = "";
	cout << "Failo kuri norit nuskaityti pavadinimas (jei jis kursiokai.txt galite tiesiog spausti 0): ";
	cin >> pav;
	if (pav == "0") pav = "kursiokai.txt";
	ifstream file(pav);
	if (file.good()) {
		cout << "Failas surastas!" << endl;
		int nd;
		int kiekis = 0;
		cout << "Kiek namu darbu pazymiu yra faile? : ";
		cin >> kiekis;
		while (cin.fail()) {
			cout << "klaida, iveskite skaiciu:  ";
			cin.clear();
			cin.ignore(200, '\n');
			cin >> kiekis;
		}
		int h;
		h = 100;
		file.unsetf(std::ios_base::skipws);
		int b = (count(std::istream_iterator<char>(file), std::istream_iterator<char>(), '\n'))-1;
		cout << "Studentu skaicius faile: " << b << endl;
		ifstream file(pav);
		file.ignore(10000, '\n');
		for (int j = 0; j < b; j++) {
			file >> stud.Vard >> stud.Pav;
			for (int i = 0; i < kiekis; i++) {
				file >> nd;
				stud.nd.push_back(nd);
			}
			file >> stud.egz;
			sort(stud.nd.begin(), stud.nd.end());
			int c;
			c = stud.nd.size();
			if (c != 0) {
				if (c % 2 == 1)
					stud.med = 0.4 * stud.nd[c / 2] + 0.6 * stud.egz;
				else
					stud.med = (stud.nd[c / 2 - 1] + stud.nd[c / 2]) / 2 * 0.4 + 0.6 * stud.egz;
			}
			if (c == 0) {
				stud.GP = stud.egz * 0.6;
			}
			else {
				float bendras = 0;
				bendras = accumulate(stud.nd.begin(), stud.nd.end(), 0);
				stud.GP = bendras / c;
				stud.GP = stud.GP * 0.4 + 0.6 * stud.egz;
			}
			grupe.push_back(stud);
			stud.nd.clear();
		}
	}
	else cout << "Ivestas failas nebuvo rastas" << endl;
	
	std::sort(grupe.begin(), grupe.end(), Tvarkymas);
	string ivestis = "";
	cout << "norint skaiciuoti galutini pazymi su vidurkiu spauskite 0, jei su mediana bet kuri kita mygtuma: ";
	cin >> ivestis;

		cout << left
			<< setw(20) << "Vardas "
			<< setw(20) << "Pavarde"
			<< setw(20)<<"Galutinis (vid) "
			<<setw(20)<<"Galutinis (med)";
		cout << "\n-------------------------------------------------------------------------------\n";

		if (ivestis == "0") {
			for (auto& d : grupe) {
				cout << left
					<< setw(20) << d.Vard
					<< setw(20) << d.Pav
					<< setw(20) << setprecision(2) << fixed << d.GP 
					<<"----\n";
			}
		}
		else  {
			for (auto& d : grupe) {
				cout << left
					<< setw(20) << d.Vard
					<< setw(20) << d.Pav
					<< setw(20) <<"----"<<setw(20)<< setprecision(2) << fixed << d.med << "\n";
			}
		}
	}
	cout << endl;
	grupe.clear();
	char a;
	cin >> a;
}
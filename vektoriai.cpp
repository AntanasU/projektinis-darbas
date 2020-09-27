// mano mas DB.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<iomanip>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::setw;
using std::setprecision;
using std::fixed;

struct studentas {
    string Vard = "", Pav = "";
    int paz[10], egz;
    float GP = 0, med;
};

int main()
{
	vector<studentas> grupe;
	studentas stud;
	cout << "iveskite studentu skaiciu: ";
	int n;
	cin >> n;
	grupe.reserve(n);
	for (int i = 0; i < n; i++) {						//ivedimas
		cout << "Iveskite " << i + 1 << "-aji varda: ";
		cin >> stud.Vard;
		cout << "pavarde: ";
		cin >> stud.Pav;
		cout << "egzamino pazymi: ";
		cin >> stud.egz;
		while (stud.egz > 10 || stud.egz < 1) {								//patikrina ar geri skaiciai
			cout << "irasete netinkamus duomenis, pabandykite dar karta ";
			cin >> stud.egz;
		}
		cout << "kiek studentas gavo pazymiu: ";
		int m;
		cin >> m;

		if (m != 0) cout << "ivestkie pazymius: \n";
		for (int i = 0; i < m; i++) {
			cin >> stud.paz[i];

			while (stud.paz[i] > 10 || stud.paz[i] < 1) {
				cout << "irasete netinkamus duomenis, pabandykite dar karta ";
				cin >> stud.paz[i];
			}
			stud.GP = stud.GP + stud.paz[i];
		}

		std::sort(stud.paz, stud.paz+m);
		if (m % 2 == 0)
			stud.med = (stud.paz[m / 2 - 1] + stud.paz[m / 2]) / 2;
		else {
			int laik = m / 2 + 0.5;
			stud.med = stud.paz[laik];
		}

		stud.GP = stud.GP / m;
		stud.GP = stud.GP * 0.4 + 0.6 * stud.egz;
		grupe.push_back(stud);

	}
	cout << std::left<< setw(20) << "vardas" << setw(20) << "pavarde"<< setw(20)<<"galutinis"<<"mediana \n";
	cout << "-------------------------------------------------------------\n";

	for (auto& tt : grupe) {
		cout << setw(20)<<tt.Vard << setw(20) << tt.Pav
			<< setw(20) << setprecision(2) << fixed << tt.GP 
			<< setw(20) << setprecision(2) << fixed <<tt.med<< "\n";
	}

		cout << endl;
		grupe.clear();
		char a;
		cin >> a;
}
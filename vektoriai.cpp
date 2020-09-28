// mano mas DB.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<random>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::setw;
using std::setprecision;
using std::fixed;
using std::rand;

struct studentas {
    string Vard = "", Pav = "", isved="";
    int nd[30], egz;
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
		cout << "egzamino pazimys: ";
		stud.egz = 1 + (rand() % 10);
		cout << stud.egz<<"\n";

		string x = "x";
		cout << n + 1 << "-ojo studento nd pazymiai, kai noresite sustoti, irasykite 0: \n";
		int j = 0;
		while (x != "0") {
			int a = 1 + rand() % 10;
			cout << a << "		";
			stud.nd[j]=a;
			stud.GP = stud.GP + (float)stud.nd[j];
			j++;
			cin >> x;
		}
		std::sort(stud.nd, stud.nd+j);
		for (int i = 0; i < j; i++)	cout << stud.nd[i] << "  "; cout << "\n";
		if (j % 2 == 0)
			stud.med = ((float)stud.nd[j / 2 - 1] + (float)stud.nd[j / 2]) / 2;
		else {
			int laik = j / 2 + 0.5;
			stud.med = stud.nd[laik];
		}

		stud.GP = stud.GP / j;
		stud.GP = stud.GP * 0.4 + 0.6 * stud.egz;
		cout << "ka norite kad isvestu galutini pazymi (0) ar mediana (bet koks kitas zenklas)? ";
		string pasirinkimas;
		cin >> pasirinkimas;
		stud.isved = pasirinkimas;
		grupe.push_back(stud);

	}

	cout << std::left<< setw(20) << "vardas" << setw(20) << "pavarde"<< "galutinis          mediana \n";
	cout << "-------------------------------------------------------------------\n";
	
		for (auto& tt : grupe) {
			cout << setw(20) << tt.Vard << setw(20) << tt.Pav;

			if (tt.isved != "0") 	cout << setw(20) << "---" << setw(20) << setprecision(2) << fixed << tt.med << "\n";
			else   cout << setw(20) << setprecision(2) << fixed << tt.GP << "\n";
	}
		grupe.clear();
		char a;
		cin >> a;
}
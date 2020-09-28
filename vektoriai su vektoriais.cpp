// mano mas DB.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<random>
#include <numeric>      

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
	string Vard = "", Pav = "", ivestis="";
	int  egz;
	vector<int>nd;
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
		stud.egz = 1 + rand() % 10;
		cout << stud.egz << "\n";
		stud.nd.reserve(20);
		string x = "x";
			cout << i + 1 << "-ojo studento nd pazymiai, kai noresite sustoti, irasykite 0: \n";


		while (x != "0") {
			int a = 1 + rand() % 10;
			cout << a << "		";
			stud.nd.push_back(a);
			cin >> x;
		}
		std::sort(stud.nd.begin(), stud.nd.end());

		int c;
		c = stud.nd.size();
		if ( c % 2 != 0)	stud.med = stud.nd[c / 2 + 0.5];
		else    			stud.med = ((float)stud.nd[c / 2 - 1] + (float)stud.nd[c / 2]) / 2;

		float suma=0;
		suma = accumulate(stud.nd.begin(), stud.nd.end(), 0);
		float vid = suma / c;
		stud.GP = vid  * 0.4 + 0.6 * stud.egz;
		cout << "\n Jei noresite gauti galutini pazymi spauskite: 0 \n jei noresite gauti mediana: bet ka kita \n";
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
				
		if (tt.ivestis != "0")	cout << setw(20) << "---" << setw(20) << setprecision(2) << fixed << tt.med << "\n";
		else 	cout << setw(20) << setprecision(2) << fixed << tt.GP << "\n";
	}
	cout << endl;
	grupe.clear();
	char a;
	cin >> a;
}
// mano mas DB.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;

struct studentas {
    string Vard = "", Pav = "";
    int paz[10], egz;
    float GP = 0;
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

	stud.GP = stud.GP / m;
	stud.GP = stud.GP * 0.4 + 0.6 * stud.egz;
	grupe.push_back(stud);

	}

	for (auto& tt : grupe) {
		cout << tt.Vard << " : "<<tt.Pav<<" : "<<tt.GP<<"\n";
	}

		cout << endl;
		grupe.clear();
		char a;
		cin >> a;
}
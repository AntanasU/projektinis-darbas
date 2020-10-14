#include "funkcijos.h"

bool Tvarkymas(const studentas& pirmas, const studentas& antras) {
	return pirmas.Vard < antras.Vard;
}
void ne_is_failo(string failo_pav) {
	vector<studentas> grupe;
	studentas stud;
	string pav = "";
	string vardai, pavardes, temp, egzaminas;
	vector<string> nd;
	int m;
	ifstream file(failo_pav);
	if (file.good()) {
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
			if (m != 0) {
				if (m % 2 == 1)
					stud.med = 0.4 * stud.nd[m / 2] + 0.6 * stud.egz;
				else
					stud.med = (stud.nd[m / 2 - 1] + stud.nd[m / 2]) / 2 * 0.4 + 0.6 * stud.egz;
			}
			if (m == 0) {
				stud.GP = stud.egz * 0.6;
			}
			else {
				float bendras = 0;
				bendras = accumulate(stud.nd.begin(), stud.nd.end(), 0);
				stud.GP = bendras / m;
				stud.GP = stud.GP * 0.4 + 0.6 * stud.egz;
			}
			grupe.reserve(grupe.capacity() + 1);
			grupe.push_back(stud);
			stud.nd.clear();
		}
		sort(grupe.begin(), grupe.end(), Tvarkymas);
		string ivestis = "";
		cout << "norint skaiciuoti galutini pazymi su vidurkiu spauskite 0, jei su mediana bet kuri kita mygtuma: ";
		cin >> ivestis;

		cout << left << setw(20) << "Vardas " << setw(20) << "Pavarde"
			<< setw(20) << "Galutinis (vid) " << setw(20) << "Galutinis (med)";
		cout << "\n-------------------------------------------------------------------------------\n";

		{
			for (auto& d : grupe) {
				cout << left << setw(20) << d.Vard << setw(20) << d.Pav;
				if (ivestis == "0")	cout << setw(20) << setprecision(2) << fixed << d.GP << "----\n";
				else  cout << setw(20) << "----" << setw(20) << setprecision(2) << fixed << d.med << "\n";
			}
		}
	}

	else cout << "Ivestas failas nebuvo rastas" << endl;

	grupe.clear();
}
#include"funkcijos.h"

bool Tvarkymas(const studentas& pirmas, const studentas& antras) {
	return pirmas.Vard < antras.Vard;
}
void isvedimas(vector<studentas> a, string ivestis, string isvedimas) {

	ofstream f1(isvedimas);

	f1 << left << setw(20) << "Vardas " << setw(20) << "Pavarde";
	if (ivestis == "0") 	
		f1 << setw(20) << "Galutinis (vid)" << endl;
	else					
		f1 << setw(20) << "Galutinis (med)" << endl;

	for (auto& d : a)
			f1 << left << setw(20) << d.Vard << setw(20) << d.Pav << setw(6) << d.GP << endl;

	a.clear();
	f1.close();
};
void is_failo(string duomenys, string isvedimas1, string isvedimas2) {
	vector<studentas> grupe;
	studentas stud;
	string pav = "";
	string vardai, pavardes, temp, egzaminas;
	vector<string> nd;
	int m;
	ifstream file(duomenys);
	try {
		if (!file.good()) {
			throw duomenys;
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
		//sort(grupe.begin(), grupe.end(), Tvarkymas);
		vector<studentas> kietekai;
		vector<studentas> vargseliai;
		kietekai.reserve(grupe.capacity());
		vargseliai.reserve(grupe.capacity());

		for (auto& d : grupe) {
			if (d.GP < 5.0)
				vargseliai.push_back(d);
			else kietekai.push_back(d);
		}

		isvedimas(vargseliai, ivestis, isvedimas1);
		isvedimas(kietekai, ivestis, isvedimas2);

	}

	catch (string pav) {
		cout << pav << " failas nerastas arba negalima atidaryti \n";
	}
}

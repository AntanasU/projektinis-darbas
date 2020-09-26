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
    float GP = 0, med;
};

int main()
{
    cout << "iveskite studentu skaiciu: ";
    int kiekis = 0;
    cin >> kiekis;
    while (kiekis < 1) {
        cout << "ivestas netinkamas skaicius, iveskite kita skaiciu ";
        cin >> kiekis;
    }

    studentas* Grupe_mas = new studentas[kiekis];

    for (int k = 0; k < kiekis; k++) {

        cout << "\n iveskite studendo varda: ";
        cin >> Grupe_mas[k].Vard;
        cout << " iveskite studendo pavarde: ";
        cin >> Grupe_mas[k].Pav;
        cout << " iveskite studendo egzamino pazymi: ";
        cin >> Grupe_mas[k].egz;
        while (Grupe_mas[k].egz > 10 || Grupe_mas[k].egz < 1) {
            cout << "irasete netinkamus duomenis, pabandykite dar karta ";
            cin >> Grupe_mas[k].egz;
        }
        int n;
        cout << "iveskite kiek pazymiu gavo studentas ";
        cin >> n;
        while (n < 1) {
            cout << "irasete netinkamus duomenis, pabandykite dar karta ";
            cin >> n;
        }
        cout << "\n iveskite studendo " << n << " semestro pazymius: ";
        for (int i = 0; i < n; i++) {
            cin >> Grupe_mas[k].paz[i];
            while (Grupe_mas[k].paz[i] > 10 || Grupe_mas[k].paz[i] < 1) {
                cout << "irasete netinkamus duomenis, pabandykite dar karta ";
                cin >> Grupe_mas[k].paz[i];
            }
            Grupe_mas[k].GP = Grupe_mas[k].GP + (float)Grupe_mas[k].paz[i];
        }

        Grupe_mas[k].GP = (float)Grupe_mas[k].GP / n;
        Grupe_mas[k].GP = Grupe_mas[k].GP * 0.4 + 0.6 * Grupe_mas[k].egz;
    }

    cout << "vardas   pavarde    galutinis pazymys / mediana" << endl;
    cout << "-----------------------------------------------" << endl;

    for (int j = 0; j < kiekis; j++) {

        cout << Grupe_mas[j].Vard << "  " << Grupe_mas[j].Pav;
        cout << "        " << Grupe_mas[j].GP << endl;

    }
    char a;
    cin >> a;
}

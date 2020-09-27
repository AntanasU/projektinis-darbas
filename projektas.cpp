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
    int paz[30], egz;
    float GP = 0, med;
};

int main()
{
    cout << "iveskite studentu skaiciu: ";
    int kiekis = 0;
    cin >> kiekis;

    studentas* Grupe_mas = new studentas[kiekis];

    for (int k = 0; k < kiekis; k++) {

        cout << "iveskite studendo varda: ";
        cin >> Grupe_mas[k].Vard;
        cout << " iveskite studendo pavarde: ";
        cin >> Grupe_mas[k].Pav;
        //cout << " iveskite studendo egzamino pazymi: ";
        //cin >> Grupe_mas[k].egz;
        //while (Grupe_mas[k].egz > 10 || Grupe_mas[k].egz < 1) {
        //    cout << "irasete netinkamus duomenis, pabandykite dar karta ";
        //    cin >> Grupe_mas[k].egz;
        //}
        cout << "egzamino pazimys: ";
        Grupe_mas[k].egz = 1 + (rand() % 10);
        cout << Grupe_mas[k].egz<<"\n";
        int n;
        cout << "iveskite kiek pazymiu gavo studentas ";
        cin >> n;
        while (n < 1) {
            cout << "irasete netinkamus duomenis, pabandykite dar karta ";
            cin >> n;
        }
        //cout << "\n iveskite studendo " << n << " semestro pazymius: \n";
        for (int i = 0; i < n; i++) {
            //cin >> Grupe_mas[k].paz[i];
            //while (Grupe_mas[k].paz[i] > 10 || Grupe_mas[k].paz[i] < 1) {
            //    cout << "irasete netinkamus duomenis, pabandykite dar karta ";
            //    cin >> Grupe_mas[k].paz[i];
            //}
            Grupe_mas[k].paz[i] = 1 + (rand() % 10);
            Grupe_mas[k].GP = Grupe_mas[k].GP + (float)Grupe_mas[k].paz[i];
        }
        std::sort(Grupe_mas[k].paz, Grupe_mas[k].paz + n);
        for (int i = 0; i < n; i++) cout << Grupe_mas[k].paz[i] << " "; cout << "\n";
        if (n % 2 == 0)
            Grupe_mas[k].med = (Grupe_mas[k].paz[n / 2 - 1] + Grupe_mas[k].paz[n / 2]) / 2;
        else {
            int laik = n / 2 + 0.5;
            Grupe_mas[k].med = Grupe_mas[k].paz[laik];

        }

        Grupe_mas[k].GP = (float)Grupe_mas[k].GP / n;
        Grupe_mas[k].GP = Grupe_mas[k].GP * 0.4 + 0.6 * Grupe_mas[k].egz;
    }

    cout <<"\n"<< std::left << setw(20) << "vardas" << setw(20) << "pavarde" << "galutinis        mediana \n";
    cout << "----------------------------------------------------------------\n";

    for (int i = 0; i < kiekis; i++) {
        cout << setw(20) << Grupe_mas[i].Vard << setw(20) << Grupe_mas[i].Pav
            << setw(20) << setprecision(2) << fixed << Grupe_mas[i].GP
            << setw(20) << setprecision(2) << fixed << Grupe_mas[i].med << "\n";

    }
    char a;
    cin >> a;
}

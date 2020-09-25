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

struct duomuo {
    string Vard, Pav;
    int paz[10], egz;
    float GP = 0, med;
};

int main()
{

    duomuo Eil; duomuo Eil_mas[5];
    vector <duomuo> Eil_vect;

    cout << "iveskite studendo varda: ";
    cin >> Eil.Vard;
    cout << "\n iveskite studendo pavarde: ";
    cin >> Eil.Pav; 
    cout << "\n iveskite studendo egzamino pazymi: ";
    cin >> Eil.egz;
    while (Eil.egz > 10 || Eil.egz < 1) {
        cout << "irasete netinkamus duomenis, pabandykite dar karta ";
        cin >> Eil.egz;
    }
    int n;
    cout << "iveskite kiek pazymiu gavo studentas \n";
    cin >> n;
    while (n < 1) {
        cout << "irasete netinkamus duomenis, pabandykite dar karta ";
        cin >> n;
    }
    cout << "\n iveskite studendo "<< n << " semestro pazymius: ";
    for (int i = 0; i < n; i++) {
        cin >> Eil.paz[i];
        while (Eil.paz[i] > 10 || Eil.paz[i] < 1) {
            cout << "irasete netinkamus duomenis, pabandykite dar karta ";
            cin >> Eil.paz[i];
        }
        Eil.GP = Eil.GP + (float)Eil.paz[i];
    }

    Eil.GP = (float)Eil.GP / 5.0;
    Eil.GP = Eil.GP * 0.4 + 0.6 * Eil.egz;
    //Eil.med = 
    //cout << "ivesta: " << Eil.Vard << " " << Eil.Pav << " " << Eil.egz;
    //for (int i = 0; i < 5; i++) cout << " " << Eil.paz[i];
    //cout << " " << Eil.GP << endl;

    Eil_vect.push_back(Eil); // su indeksu 0
    Eil_vect.push_back(Eil); // su indeksu 1

    cout << "vardas   pavarde    galutinis pazymys / mediana" << endl;
    cout << "_______________________________________" << endl;

    for (int j = 0; j < 2; j++) {

        cout << Eil_vect[j].Vard << "  " << Eil_vect[j].Pav ;
        //for (int i = 0; i < 5; i++) cout << " " << Eil_vect[j].paz[i];
        cout << "        " << Eil_vect[j].GP << endl;

    }        
    char a;
    cin >> a;
    Eil_vect.clear();
}

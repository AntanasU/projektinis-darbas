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
    string Vard;
    string Pav;
    int paz[10];
    int egz;
    float GP=0;
};

int main()
{
    duomuo Eil; duomuo Eil_mas[5];
    vector <duomuo> Eil_vect;
    cout << "sveiki iveskite Eil duomenis: (vardas, pavarde, egzaminas, 5 semestro pazymiai)\n";
    cin >> Eil.Vard >> Eil.Pav >> Eil.egz;
    for (int i = 0; i < 5; i++) {
        cin >> Eil.paz[i];
        Eil.GP = Eil.GP + (float)Eil.paz[i];

    }
    Eil.GP = (float)Eil.GP / 5.0;
    Eil.GP = Eil.GP * 0.4 + 0.6 * Eil.egz;
    cout << "ivesta: " << Eil.Vard << " " << Eil.Pav << " " << Eil.egz;
    for (int i = 0; i < 5; i++) cout << " " << Eil.paz[i];
    cout << " " << Eil.GP << endl;

    Eil_vect.push_back(Eil); // su indeksu 0
    Eil_vect.push_back(Eil); // su indeksu 1

    Eil_vect[1].GP = 25;

    cout << endl<<endl;

    for (int j = 0; j < 2; j++) {

        cout << "ivesta: " << Eil_vect[j].Vard << " " << Eil_vect[j].Pav << " " << Eil_vect[j].egz;
        for (int i = 0; i < 5; i++) cout << " " << Eil_vect[j].paz[i];
        cout << " " << Eil_vect[j].GP << endl;


    }        
    char a;
    cin >> a;
    Eil_vect.clear();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

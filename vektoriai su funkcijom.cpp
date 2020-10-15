#include"is_failo.h"
#include"ne_is_failo.h"

int main()
{
	string pasirinkimas;
	cout << "jei norite skaityti duomenis is failo spauskite 0, jei ne bet kuri kita mygtuka:  ";
	cin >> pasirinkimas;
	if (pasirinkimas != "0") 
		ne_is_failo();
	else 
		is_failo("kursiokai.txt");
	system("PAUSE");
}
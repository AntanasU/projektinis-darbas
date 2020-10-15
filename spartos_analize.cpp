#include"bendra.h"

int main()
{
	string a = "";
	cout << "norint skaiciuoti galutini pazymi su vidurkiu spauskite 0, jei su mediana bet kuri kita mygtuma: ";
	cin >> a;

	bendra(a, 5, 1000);
	bendra(a, 5, 10000);
	bendra(a, 5, 100000);
	bendra(a, 5, 1000000);
	bendra(a, 5, 10000000);
}
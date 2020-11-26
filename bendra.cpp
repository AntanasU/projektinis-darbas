#include"bendra.h"
void letas(string ivestis, int nd, int eilutes)
{
	cout << "\n \n L E T A S \n (kuriami 2 nauji konteineriai)\n \n";
	failo_kurimas(nd, eilutes);
	string duom_pav = to_string(eilutes) + ".txt";
	string v_pav = to_string(eilutes) + "v.txt";
	string k_pav = to_string(eilutes) + "k.txt";
	V_letas(ivestis, duom_pav, v_pav, k_pav);
	system("PAUSE");
	L_letas(ivestis, duom_pav, v_pav, k_pav);
	system("PAUSE");
};

void greitas(string ivestis, int nd, int eilutes)
{
	cout << "\n \n G R E I T A S \n (kuriamas tik 1 naujas konteineris)\n \n";
	failo_kurimas(nd, eilutes);
	string duom_pav = to_string(eilutes) + ".txt";
	string v_pav = to_string(eilutes) + "v.txt";
	string k_pav = to_string(eilutes) + "k.txt";
	V_greitas(ivestis, duom_pav, v_pav, k_pav);
	system("PAUSE");
	L_greitas(ivestis, duom_pav, v_pav, k_pav);
	system("PAUSE");
};
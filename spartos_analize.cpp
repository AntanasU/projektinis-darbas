#include"funkcijos.h"
#include "kurimas.h"

int main()
{
	failo_kurimas(5, 100, "naujas_failas");
	is_failo("naujas_failas", "vargsiukai.txt", "kietekai.txt");
	system("PAUSE");
}
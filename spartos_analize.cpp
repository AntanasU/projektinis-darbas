#include"funkcijos.h"
#include "kurimas.h"

int main()
{
	failo_kurimas(6, 100, "naujas_failas.txt");
	is_failo("naujas_failas.txt");
	system("PAUSE");
}
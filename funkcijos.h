#pragma once
#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<random>
#include <numeric>      
#include <fstream>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::setw;
using std::setprecision;
using std::fixed;
using std::rand;
using std::left;
using std::ifstream;

struct studentas {
	string Vard = "", Pav = "", ivestis = "";
	int  egz = 0;
	vector<int>nd;
	float GP = 0, med = 0;
};

void ne_is_failo();
void is_failo(string failo_pav);

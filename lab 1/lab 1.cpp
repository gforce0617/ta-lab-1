#include <iostream>
#include <string>
#include <fstream>
#include "DNF.h"

int main()
{
	setlocale(LC_ALL, "ru");
	string path = "scale.txt";
	
	ifstream fin;

	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
		fin.close();
		return 0;
	}

	string str;
	getline(fin, str);

	DNF dnf(str);

	dnf.minimize();
	dnf.print("mdnf.txt");

	fin.close();
	return 0;
}



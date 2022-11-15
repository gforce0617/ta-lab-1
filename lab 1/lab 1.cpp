#include <iostream>
#include <string>
#include <fstream>
#include "DNF.h"

int main()
{
	string path = "scale.txt";

	ifstream fin;

	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Fail open scale" << endl;
		fin.close();
		return 0;
	}

	string str;
	getline(fin, str);


	DNF dnf(str);

	vector<string> str_dnf = dnf.str_sdnf();



	dnf.minimize(str_dnf);
	dnf.print("mdnf.txt");

	fin.close();

	system("pause");
	return 0;


}




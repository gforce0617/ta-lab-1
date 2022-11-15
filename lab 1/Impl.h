#pragma once
#include <string>
#include <iostream>
using namespace std;

class Impl
{
private:
	int num;
	int ind;
	int p;
	bool pw;

	static int count(int);


public:
	Impl(int);
	Impl(int, int);

	static string to2(int);

	static Impl* patch(Impl&, Impl&);
	string print_result();

	bool get_pw();
	int get_num();
	int get_p();


	friend ostream& operator<<(ostream& os, const Impl& d);
	friend bool operator==(const Impl& a, const Impl& b);

};


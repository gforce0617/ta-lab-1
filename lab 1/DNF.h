#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "Impl.h"


using namespace std;

class DNF
{
private:
	vector<Impl> Data;
	vector<int> index_;

public:
	DNF(string);
	~DNF();

	void minimize(vector<string>&);
	void print(string);

	vector<string> str_sdnf();
	//Impl& getImpl(int);

};

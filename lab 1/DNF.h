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
	
public:
	DNF(string);
	~DNF();

	void minimize();
	void print(string);
	
	//Impl& getImpl(int);
	
};


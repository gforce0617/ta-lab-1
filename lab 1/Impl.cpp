#pragma once
#include "Impl.h"

Impl::Impl(int num)
{
	this->num = num;
	this->ind = this->count(num);
	this->p = 0;
	this->pw = 0;
}

Impl::Impl(int num, int pointer)
{
	this->num = num;
	this->ind = this->count(num);
	this->p = pointer;
	this->pw = 0;
}

int Impl::count(int num)
{
	int count = 0;
	string buff = Impl::to2(num);

	for (int i = 0; i < buff.size(); i++)
	{
		if (buff[i] == '1')
			count++;
	}

	return count;
}

string Impl::to2(int num)
{
	string buff;

	for (int i = 0; i < 4; i++)
	{
		buff += char('0' + num % 2); // ��������� � �����
		num = num / 2;
	}

	return string(buff.crbegin(), buff.crend());

}

Impl* Impl::patch(Impl& n1, Impl& n2)
{
	//Impl *result;
	if (n1.num < n2.num && n1.p == n2.p && n2.ind - n1.ind == 1 && Impl::count(n2.num - n1.num) == 1)
	{
		//result= new Impl(n1.num);
		//result->p = n1.p + n2.num - n1.num;
		n1.pw = 1;
		n2.pw = 1;
		return new Impl(n1.num, n1.p + n2.num - n1.num);
	}
	else
	{
		//result = nullptr;
		return nullptr;
	}
	//return result;
}

string Impl::print_result()
{
	string n = Impl::to2(this->num);
	string p = Impl::to2(this->p);
	string result = "";
	for (int i = 0; i < n.size(); i++)
	{
		if (p[i] == '1')
			result += '-';
		else
			result += n[i];
	}
	//cout << result << endl;
	return result;
}

bool Impl::get_pw()
{
	return this->pw;
}

int Impl::get_p()
{
	return this->p;
}

int Impl::get_num()
{
	return this->num;
}


ostream& operator<<(ostream& os, const Impl& d)
{
	return os << d.num << ' ' << d.ind << ' ' << d.p << ' ' << d.pw << endl;
}

bool operator==(const Impl& a, const Impl& b)
{
	return a.num == b.num && a.ind == b.ind && a.p == b.p && a.pw == b.pw;
}
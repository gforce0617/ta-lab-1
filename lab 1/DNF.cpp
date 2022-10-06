#include "DNF.h"

DNF::DNF(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '1' || str[i] == '-')
		{
			this->Data.push_back(Impl(i));
		}
	}
}

DNF::~DNF()
{
	this->Data.clear();
}

void DNF::minimize()
{
	vector<Impl> newData;
	int count;
	do 
	{
		count = 0;
		for (int i = 0; i < Data.size() -1 ; i++)
		{
			for (int j = i + 1; j < Data.size(); j++)
			{
				Impl* buff = Impl::patch(Data[i], Data[j]);
				if (buff != nullptr)
				{
					if(find(newData.begin(),newData.end(),*buff) == newData.end())
					{
						newData.push_back(*buff);
						count++;
					}
					
				}
			}
			
			
		}

		for (auto elem : Data)
		{
			if (elem.get_pw() == 0)
				newData.push_back(elem);
		}

		for (auto el : newData)
		{
			cout<<el;
		}
		cout << "________________________________________________" << endl;
		Data.clear();
		Data.insert(Data.begin(), newData.begin(), newData.end());
		newData.clear();
	} while (count != 0);
}

void DNF::print(string path)
{
	ofstream fout;

	fout.exceptions(ofstream::badbit | ofstream::failbit);

	try
	{
		fout.open(path);
	}
	catch (const std::exception& ex)
	{
		cout << "Ошибка открытия" << endl;
		cout << ex.what() << endl;
		exit;
	}

	for (auto elem : this->Data)
	{
		string p_str = Impl::to2(elem.get_p());
		string num_str = Impl::to2(elem.get_num());

		

		string res="";

		for (int i = 0; i < p_str.size(); i++)
		{
			if (p_str[i] == '1')
			{
				res += "-";
			}
			else
			{
				res += num_str[i];
			}
		}

		fout << res << endl;
	}
	fout.close();
}

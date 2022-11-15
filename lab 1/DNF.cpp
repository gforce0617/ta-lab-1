#include "DNF.h"
#include <algorithm>

DNF::DNF(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '1')
		{
			this->Data.push_back(Impl(i));
			this->index_.push_back(i);
		}
		else if (str[i] == '-')
			this->Data.push_back(Impl(i));
	}
}

DNF::~DNF()
{
	this->Data.clear();
}

void DNF::minimize(vector<string>& sdnf)
{
	vector<Impl> newData;
	int count;
	do
	{
		count = 0;
		for (int i = 0; i < Data.size() - 1; i++)
		{
			for (int j = i + 1; j < Data.size(); j++)
			{
				Impl* buff = Impl::patch(Data[i], Data[j]);
				if (buff != nullptr)
				{
					if (find(newData.begin(), newData.end(), *buff) == newData.end())
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
			cout << el;
		}
		cout << "________________________________________________" << endl;
		Data.clear();
		Data.insert(Data.begin(), newData.begin(), newData.end());
		newData.clear();
	} while (count != 0);

	vector<vector<int>> arr;
	vector<int> column_count;
	vector<int> line_count;

	for (int i = 0; i < sdnf.size(); i++)
	{
		vector<int> buff;
		int cnt = 0;
		for (int j =0; j < Data.size(); j++)
		{
			string str = Data[j].print_result();
			int count = 0;
			for (int k = 0; k < 4; k++)
			{
				if (str[k] == '-' || sdnf[i][k] == str[k])
					count++;

			}
			if (count == 4)
			{
				buff.push_back( 1);
				cnt++;
			}
			else
				buff.push_back(0);
		}
		column_count.push_back(cnt);
		arr.push_back(buff);
		buff.clear();
	}
	cout << "1" << endl;
	for (auto el : arr)
	{
		for (auto j : el)
		{
			cout << j;
		}
		cout << endl;
	}
		

	for (int j = 0; j < arr[0].size(); j++)
	{
		int count = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			count += arr[i][j];
		}
		line_count.push_back(count);
	}

	vector<int> index_line;
	vector<Impl> res;
	do
	{
		int min = sdnf.size() + 1;
		int min_column = 0;
		for (int i = 0; i < column_count.size(); i++)
		{
			if (column_count[i] < min)
			{
				min = column_count[i];
				min_column = i;
			}
		}

		//for (int i = 0; i < arr.size(); i++)
		//{
		//	if (column_count[i] == min_column)
		//	{
		int index;
		for (int j = 0; j < arr[min_column].size(); j++)
		{
			if (arr[min_column][j] == 1)
				index_line.push_back(j);
		}

		if (index_line.size() > 1)
		{
			int max_count = 0;
			for (int j = 0; j < index_line.size(); j++)
			{
				if (line_count[j] > max_count)
				{
					max_count = line_count[j];
					index = j;
				}
			}
		}
		else
			index = index_line[0];
		res.push_back(Data[index]);
		//Data.erase(Data.begin() + index);
		vector<int>delete_index;
		for (int j = 0; j < arr.size(); j++)
		{
			if (arr[j][index] == 1)
			{
				delete_index.push_back(j);
			}
		}
		for (int j=0;j<delete_index.size();j++)
		{
			column_count.erase(column_count.begin() + delete_index[j]);
			arr[delete_index[j]].clear();
			arr.erase(arr.begin() + delete_index[j]);
			for (int k = 0; k < delete_index.size(); k++)
				delete_index[k]--;
		}
		index_line.clear();
		delete_index.clear();
				//line_count.erase(line_count.begin() + index);
				//break;

			//}
		//}
	} while (arr.size() > 0);


	Data.clear();
	Data.insert(Data.begin(), res.begin(), res.end());
	res.clear();

}

vector<string> DNF::str_sdnf()
{
	vector<string> res;
	for (auto ine : this->Data)
	{
		for (auto el : this->index_)
			if (el == ine.get_num())
			{
				res.push_back(ine.print_result());
				break;
			}
	}
	return res;
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
		cout << "Fail open mdnf" << endl;
		cout << ex.what() << endl;
		exit;
	}

	for (auto elem : this->Data)
	{
		fout << elem.print_result() << endl;
	}
	fout.close();
}


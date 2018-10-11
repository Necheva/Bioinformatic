#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	string sub_string;
	string input_string;
	string tmp;
	vector<string> ARR;
	vector<string> AUXILIARY_MASSIV;
	int index = 0;
	int count = 0;
	int max_count = 0;
	cin >> sub_string;
	cin >> input_string;
	AUXILIARY_MASSIV.push_back(sub_string);
	for (size_t i = 0; i < input_string.size() - sub_string.size() + 1; i++)
	{
		for (size_t j = 0; j < sub_string.size(); j++)
		{
			tmp += input_string[i + j];
		}
		ARR.push_back(tmp);
		tmp = "";
	}
	for (size_t i = 0; i < ARR.size(); i++)
	{
		if (ARR[i] == AUXILIARY_MASSIV[index])
		{
			count++;
		}
		if (max_count < count)
		{
			max_count = count;
		}
	}
	cout << max_count;

}

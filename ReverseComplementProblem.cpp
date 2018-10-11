#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
	map<string, string> key_value = 
	{
		{"A","T"},
		{"C","G"},
		{"T","A"},
		{"G","C"}

	};
	string input_string;
	string tmp;
	int k = 0;
	vector<string> arr;
	vector<string> AUXILIARY_MASSIV;
	cin >> input_string;
	for (auto i = 0; i < input_string.size(); i++)
	{
		tmp += input_string[i];
		arr.push_back(tmp);
		tmp = "";
	}
	for (int j = 0; j < arr.size(); j++)
	{
		for (auto i = key_value.begin(); i != key_value.end(); ++i)
		{
			if (arr[j] == i->first)
				AUXILIARY_MASSIV.push_back(i->second);
		}
	}
	std::reverse(AUXILIARY_MASSIV.begin(), AUXILIARY_MASSIV.end());
	for (auto x : AUXILIARY_MASSIV) 
		cout << x;
}

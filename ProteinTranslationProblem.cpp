
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
	map<string, string> key_value =
	{
		{"AAU","N"},
		{"AAC","N"},
		{"AAA","K"},
		{"AAG","K"},
		{"ACU","T"},
		{"ACC","T"},
		{"ACA","T"},
		{"ACG","T"},
		{"AGU","S"},
		{"AGC","S"},
		{"AGA","R"},
		{"AGG","R"},
		{"AUU","I"},
		{"AUC","I"},
		{"AUA","I"},
		{"AUG","M"},

		{"CAU","H"},
		{"CAC","H"},
		{"CAA","Q"},
		{"CAG","Q"},
		{"CCU","P"},
		{"CCC","P"},
		{"CCA","P"},
		{"CCG","P"},
		{"CGU","R"},
		{"CGC","R"},
		{"CGA","R"},
		{"CGG","R"},
		{"CUU","L"},
		{"CUC","L"},
		{"CUA","L"},
		{"CUG","L"},

		{"GAU","D"},
		{"GAC","D"},
		{"GAA","E"},
		{"GAG","E"},
		{"GCU","A"},
		{"GCC","A"},
		{"GCA","A"},
		{"GCG","A"},
		{"GGU","G"},
		{"GGC","G"},
		{"GGA","G"},
		{"GGG","G"},
		{"GUU","V"},
		{"GUC","V"},
		{"GUA","V"},
		{"GUG","V"},

		{"UAU","Y"},
		{"UAC","Y"},
		{"UAA",""},
		{"UAG",""},
		{"UCU","S"},
		{"UCC","S"},
		{"UCA","S"},
		{"UCG","S"},
		{"UGU","C"},
		{"UGC","C"},
		{"UGA",""},
		{"UGG","W"},
		{"UUU","F"},
		{"UUC","F"},
		{"UUA","L"},
		{"UUG","L"},

	};
	string input_string;
	string tmp;
	int k = 0;
	vector<string> arr;
	vector<string> AUXILIARY_MASSIV;
	int count = 0;
	cin >> input_string;
	for (auto i = 0; i < input_string.size(); i++)
	{
		tmp += input_string[i];
		count++;
		if (count == 3)
		{
			arr.push_back(tmp);
			tmp = "";
			count = 0;
		}
	}
	for (int j = 0; j < arr.size(); j++)
	{
		for (auto i = key_value.begin(); i != key_value.end(); ++i)
		{
			if (arr[j] == i->first)
				AUXILIARY_MASSIV.push_back(i->second);
		}
	}
	for (auto x : AUXILIARY_MASSIV)
		cout << x;
}

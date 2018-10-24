#include <iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int LOGIC(string X);

int main()
{
	
	string input_string;
	string tmp;
	int count = 0;
	int count_2 = 0;
	vector<string> arr;
	vector<string> AUXILIARY_MASSIV;
	vector<int>result;
	result.push_back(0);
	cin >> input_string;
	result.push_back(LOGIC(input_string));
	string new_string = input_string + input_string;
	for (auto count = 1; count < input_string.size(); count++)
	{
		for (auto j = 0; j < input_string.size(); j++)
		{
			arr.push_back(new_string.substr(j, count));
		}
	}
	
	for (auto i = 0; i < arr.size(); i++)
	{
		result.push_back(LOGIC(arr[i]));
	}
	sort(result.begin(), result.end());
	for (auto x : result)
		cout << x << " ";

}

int LOGIC(string A)
{
	map<string, int> key_value =
	{
		{"A",71},
		{"G",57},
		{"S",87},
		{"P",97},
		{"V",99},
		{"T",101},
		{"C",103},
		{"I",113},
		{"L",113},
		{"N",114},
		{"D",115},
		{"K",128},
		{"Q",128},
		{"E",129},
		{"M",131},
		{"H",137},
		{"F",147},
		{"R",156},
		{"Y",163},
		{"W",186}
	};

	vector<string> arr;
	string tmp;
	int count = 0;
	for (auto i = 0; i < A.size(); i++)
	{
		tmp += A[i];
		arr.push_back(tmp);
		tmp = "";
	}
	for (auto j = 0; j < arr.size(); j++)
	{
		for (auto k = key_value.begin(); k != key_value.end(); ++k)
		{
			if (arr[j] == k->first)
			{
				count += k->second;
				break;
			}
		}
	}
	return count;
}

// ConsoleApplication11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

unsigned counting(string & f, string & s)
{
	long long int result = 0;;
	for (size_t i = 0; i < f.size(); i++)
	{
		if (f[i] != s[i])
		{
			result++;
		}
	}
	return result;
}
int main()
{
	unsigned k;
	vector<string> dna;
	cin >> k;
	string temp_elem;
	string symbols = "ACTG";
	vector<string> DNA_string;
	vector< vector<string> > matrix_motifs;
	while(cin >> temp_elem)
	{ 
		DNA_string.push_back(temp_elem);
	}
	for (size_t i = 0; i < DNA_string.size(); i++)
	{
		vector<string> temp;
		for (size_t j = 0; j < DNA_string[i].size() - k + 1; j++)
		{
			string motif = DNA_string[i].substr(j, k);
			temp.push_back(motif);
		}
		matrix_motifs.push_back(temp);
	}
	const unsigned total_words_count = pow(symbols.size(), k);
	const char* word = "ACTG";
	string tmp;
	vector<string> arg;
	if (k == 1)
	{
		for (int i = 0; i < total_words_count; ++i)
		{

			tmp += word[i & 0x03];
			arg.push_back(tmp);
			tmp = "";
		}
	}
	if (k == 2)
	{
		for (int i = 0; i < total_words_count; ++i)
		{

			tmp += word[i >> 2 & 0x03];
			tmp += word[i & 0x03];
			arg.push_back(tmp);
			tmp = "";
		}
	}
	if (k == 3)
	{
		for (int i = 0; i < total_words_count; ++i)
		{

			tmp += word[i >> 4 & 0x03];
			tmp += word[i >> 2 & 0x03];
			tmp += word[i & 0x03];
			arg.push_back(tmp);
			tmp = "";
		}
	}
	if (k == 4)
	{
		for (int i = 0; i < total_words_count; ++i)
		{

			tmp += word[i >> 6 & 0x03];
			tmp += word[i >> 4 & 0x03];
			tmp += word[i >> 2 & 0x03];
			tmp += word[i & 0x03];
			arg.push_back(tmp);
			tmp = "";
		}
	}
	if (k == 5)
	{
		for (int i = 0; i < total_words_count; ++i)
		{

			tmp += word[i >> 8 & 0x03];
			tmp += word[i >> 6 & 0x03];
			tmp += word[i >> 4 & 0x03];
			tmp += word[i >> 2 & 0x03];
			tmp += word[i & 0x03];
			arg.push_back(tmp);
			tmp = "";
		}
	}
	if (k == 6)
	{
		for (int i = 0; i < total_words_count; ++i)
		{
			tmp += word[i >> 10 & 0x03];
			tmp += word[i >> 8 & 0x03];
			tmp += word[i >> 6 & 0x03];
			tmp += word[i >> 4 & 0x03];
			tmp += word[i >> 2 & 0x03];
			tmp += word[i & 0x03];
			arg.push_back(tmp);
			tmp = "";
		}
	}
	if (k == 7)
	{
		for (int i = 0; i < total_words_count; ++i)
		{
			tmp += word[i >> 12 & 0x03];
			tmp += word[i >> 10 & 0x03];
			tmp += word[i >> 8 & 0x03];
			tmp += word[i >> 6 & 0x03];
			tmp += word[i >> 4 & 0x03];
			tmp += word[i >> 2 & 0x03];
			tmp += word[i & 0x03];
			arg.push_back(tmp);
			tmp = "";
		}
	}
	if (k == 8)
	{
		for (int i = 0; i < total_words_count; ++i)
		{
			tmp += word[i >> 14 & 0x03];
			tmp += word[i >> 12 & 0x03];
			tmp += word[i >> 10 & 0x03];
			tmp += word[i >> 8 & 0x03];
			tmp += word[i >> 6 & 0x03];
			tmp += word[i >> 4 & 0x03];
			tmp += word[i >> 2 & 0x03];
			tmp += word[i & 0x03];
			arg.push_back(tmp);
			tmp = "";
		}
	}
	if (k == 9)
	{
		for (int i = 0; i < total_words_count; ++i)
		{
			tmp += word[i >> 16 & 0x03];
			tmp += word[i >> 14 & 0x03];
			tmp += word[i >> 12 & 0x03];
			tmp += word[i >> 10 & 0x03];
			tmp += word[i >> 8 & 0x03];
			tmp += word[i >> 6 & 0x03];
			tmp += word[i >> 4 & 0x03];
			tmp += word[i >> 2 & 0x03];
			tmp += word[i & 0x03];
			arg.push_back(tmp);
			tmp = "";
		}
	}
	if (k == 10)
	{
		for (int i = 0; i < total_words_count; ++i)
		{
			tmp += word[i >> 18 & 0x03];
			tmp += word[i >> 16 & 0x03];
			tmp += word[i >> 14 & 0x03];
			tmp += word[i >> 12 & 0x03];
			tmp += word[i >> 10 & 0x03];
			tmp += word[i >> 8 & 0x03];
			tmp += word[i >> 6 & 0x03];
			tmp += word[i >> 4 & 0x03];
			tmp += word[i >> 2 & 0x03];
			tmp += word[i & 0x03];
			arg.push_back(tmp);
			tmp = "";
		}
	}
	if (k == 11)
	{
		for (int i = 0; i < total_words_count; ++i)
		{
			tmp += word[i >> 20 & 0x03];
			tmp += word[i >> 18 & 0x03];
			tmp += word[i >> 16 & 0x03];
			tmp += word[i >> 14 & 0x03];
			tmp += word[i >> 12 & 0x03];
			tmp += word[i >> 10 & 0x03];
			tmp += word[i >> 8 & 0x03];
			tmp += word[i >> 6 & 0x03];
			tmp += word[i >> 4 & 0x03];
			tmp += word[i >> 2 & 0x03];
			tmp += word[i & 0x03];
			arg.push_back(tmp);
			tmp = "";
		}
	}
	if (k == 12)
	{
		for (int i = 0; i < total_words_count; ++i)
		{
			tmp += word[i >> 22 & 0x03];
			tmp += word[i >> 20 & 0x03];
			tmp += word[i >> 18 & 0x03];
			tmp += word[i >> 16 & 0x03];
			tmp += word[i >> 14 & 0x03];
			tmp += word[i >> 12 & 0x03];
			tmp += word[i >> 10 & 0x03];
			tmp += word[i >> 8 & 0x03];
			tmp += word[i >> 6 & 0x03];
			tmp += word[i >> 4 & 0x03];
			tmp += word[i >> 2 & 0x03];
			tmp += word[i & 0x03];
			arg.push_back(tmp);
			tmp = "";
		}
	}

	unsigned tmps = 9999999999999;
	string kost;
    unsigned result;
	for (size_t g = 0; g < arg.size(); g++)
	{
		result = 0;
		for (size_t i = 0; i < matrix_motifs.size(); i++)
		{
			vector<unsigned> abc;
			for (size_t j = 0; j < matrix_motifs[i].size(); j++)
			{
				abc.push_back(counting(matrix_motifs[i][j], arg[g]));
			}
			result += *min_element(abc.begin(), abc.end());
		}
		if (tmps > result)
		{
			tmps = result;
			kost = arg[g];
		}
	}

	cout << kost << '\n';
}

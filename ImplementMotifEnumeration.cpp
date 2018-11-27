#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
unsigned count(std::string & first, std::string & second)
{
	unsigned result = 0;;
	for (size_t i = 0; i < first.size(); i++)
	{
		if (first[i] != second[i]) 
		{ 
			result++;
		}
	}
	return result;
}
using namespace std;
int main()
{
	int k;
	int d;
	string input_string;
	vector<string> DNA_string;
	vector<vector<string> > matrix_motifs;
	vector<string> result;
	string symbols = "ACTG";
	cin >> k;
	cin >> d;
	while(cin>>input_string)
	{
		DNA_string.push_back(input_string);
	}
	for (size_t i = 0; i < DNA_string.size(); i++)
	{
		std::vector<string> temp_vector_k_motifs;
		for (size_t j = 0; j < DNA_string[i].size() - k + 1; j++)
		{
			string k_motif = DNA_string[i].substr(j, k);
			temp_vector_k_motifs.push_back(k_motif);
		}
		matrix_motifs.push_back(temp_vector_k_motifs);
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

	for (auto z = 0; z < arg.size(); z++)
	{
		unsigned tmp = 0;
		for (auto i = 0; i < matrix_motifs.size(); i++)
		{
			bool metka = false;
			for (auto j = 0; j < matrix_motifs[i].size(); j++)
			{
				if (count(arg[z], matrix_motifs[i][j]) <= d)
				{
					metka = true;
					break;
				}
			}
			if (metka)
			{ 
				tmp++; 
			}
			else 
			{ 
				break; 
			}
		}
		if (tmp == matrix_motifs.size())
		{ 
			result.push_back(arg[z]); 
		}
	}

	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());

	for (size_t i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << ' ';
	}
	std::cout << '\n';
	return 0;

}


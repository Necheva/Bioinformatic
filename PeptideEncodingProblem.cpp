#include <iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

string DNA_TO_RNA(string dna);
string RNA_TO_DNA(string rna);
string REVERS_RNA(string rna);
string Translation(string rna);


int main()
{

	string input_string_dna;
	string input_amino_acid;
	string rna;
	string new_revers_rna;
	string tmp_rna;
	string tmp_revers_rna;
	string tmp_output = "";
	string tmp_output_2 = "";
	int counter = 0;
	int counter_2 = 0;

	cin >> input_string_dna;
	cin >> input_amino_acid;

	rna = DNA_TO_RNA(input_string_dna);
	new_revers_rna = REVERS_RNA(rna);

	for (auto i = 0; i < rna.size() - (input_amino_acid.size()*3)+1; i++)
	{
		tmp_rna = rna.substr(i, input_amino_acid.size() * 3);
		if (input_amino_acid.compare(Translation(tmp_rna)) == 0)
		{
			tmp_rna = RNA_TO_DNA(tmp_rna);
			cout << tmp_rna << endl;
			tmp_rna = "";
		}
	}
	for (auto i = 0; i < new_revers_rna.size() - (input_amino_acid.size() * 3) + 1; i++)
	{
		tmp_revers_rna = new_revers_rna.substr(i, input_amino_acid.size() * 3);
		if (input_amino_acid.compare(Translation(tmp_revers_rna)) == 0)
		{
			tmp_revers_rna = RNA_TO_DNA(REVERS_RNA(tmp_revers_rna));
			cout<< tmp_revers_rna << endl;
			tmp_revers_rna = "";
		}
	}

}

string	DNA_TO_RNA(string dna)
{
	vector<string> arr;
	string tmp;
	string result = "";
	for (auto i = 0; i < dna.size(); i++)
	{
		tmp += dna[i];
		arr.push_back(tmp);
		tmp = "";
	}
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == "T")
		{
			arr[i] = "U";
		}
	}
	for (int i = 0; i < arr.size(); i++)
	{
		result += arr[i];
	}
	return result;
}

string	RNA_TO_DNA(string rna)
{
	vector<string> arr;
	string tmp;
	string result = "";
	for (auto i = 0; i < rna.size(); i++)
	{
		tmp += rna[i];
		arr.push_back(tmp);
		tmp = "";
	}
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == "U")
		{
			arr[i] = "T";
		}
	}
	for (int i = 0; i < arr.size(); i++)
	{
		result += arr[i];
	}
	return result;
}

string REVERS_RNA(string rna)
{
	map<string, string> key_value =
	{
		{"A","U"},
		{"C","G"},
		{"U","A"},
		{"G","C"}

	};
	string result = "";
	vector<string> arr;
	vector<string> AUXILIARY_MASSIV;
	string tmp;
	for (auto i = 0; i < rna.size(); i++)
	{
		tmp += rna[i];
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
	for (int i = 0; i < AUXILIARY_MASSIV.size(); i++)
	{
		result += AUXILIARY_MASSIV[i];
	}
	return result;
}

string Translation(string rna)
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

	vector<string> arr;
	vector<string> AUXILIARY_MASSIV;
	string tmp;
	string result = "";
	int count = 0;
	for (auto i = 0; i < rna.size(); i++)
	{
		tmp += rna[i];
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
	for (int i = 0; i < AUXILIARY_MASSIV.size(); i++)
	{
		result += AUXILIARY_MASSIV[i];
	}
	return result;
}

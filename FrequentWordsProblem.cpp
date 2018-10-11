#include <iostream>
#include<string>
#include<vector>
using namespace std;
int main(int argc, char** argv)
{
	string dna;
	vector<string> arr;
	int L;
	cin >> dna;
	cin >> L;
	int k = 0;
	int z = 0;
	int count = 0;
	string tmp;
	
	for (size_t i = 0; i < dna.size()-L+1; i++)
	{
		for (size_t j = 0; j < L; j++)
		{
			tmp += dna[i + j];
		}
		arr.push_back(tmp);
		tmp = "";
	}
	int maxcount(1);
	int index = -1;
	int List[100];
	for (int i = 0; i < arr.size(); i++)
	{
		count = 0;
		for (int j = i; j < arr.size(); j++)
		{
			if (arr[i] == arr[j])
			{
				count++;
			}
		}
		if (count==maxcount)
		{
			List[k] = i;
			k++;
		}
		if (count > maxcount)
		{
			maxcount = count;
			index = i;
			k = 1;
			List[0] = i;
		}
	}
	for (int a = k-1; a >= 0; a--)
	{
		cout<< arr[List[a]] << " ";
	}
}

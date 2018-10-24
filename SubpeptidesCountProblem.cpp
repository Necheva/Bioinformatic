#include <iostream>

long long int Subpeptides_Count_Problem(long long int N);
int main() {
	long long int N = 0;
	std::cin >> N;
	std::cout << Subpeptides_Count_Problem(N) << std::endl;
	return 0;
}
long long int Subpeptides_Count_Problem(long long int N)
{
	return N * (N - 1);
}

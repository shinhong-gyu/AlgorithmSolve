#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int sizes[6];
	for (int i = 0; i < 6; i++)
	{
		cin >> sizes[i];
	}

	int T, P;
	cin >> T >> P;

	int count = 0;

	for (auto size : sizes)
	{
		if (size % T == 0) count += size / T;
		else count += ((size / T) + 1);
	}
	cout << count << endl;
	cout << N / P << " " << N % P << endl;
}
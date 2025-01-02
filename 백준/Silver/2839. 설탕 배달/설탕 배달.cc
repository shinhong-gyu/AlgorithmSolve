#include <iostream>

using namespace std;

int sugarBundle(int N)
{
	int bundle = 0;
	while (N > 0)
	{
		if (N % 5 == 0)
		{
			bundle += N / 5;
			N = 0;
		}
		else
		{
			N -= 3;
			bundle++;
		}
	}
	if (N < 0) return -1;
	return bundle;
}

int main()
{
	int N;
	cin >> N;

	cout << sugarBundle(N) << endl;
}
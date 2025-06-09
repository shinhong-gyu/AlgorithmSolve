#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N;
	cin >> N;

	long long count = N;

	for (long p = 2; p <= sqrt(N); p++)
	{
		if (N % p == 0)
		{
			count -= (count / p);

			while (N % p == 0)
			{
				N /= p;
			}
		}
	}

	if (N > 1)
	{
		count = count - count / N;
	}

	cout << count;
}
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<bool> isPrime(N + 1, true);
	vector<int> Primes;

	isPrime[0] = false;
	isPrime[1] = false;

	if (N > 1)
	{
		for (int i = 2; i <= sqrt(N); i++)
		{
			if (isPrime[i])
			{
				for (int j = i + i; j <= N; j += i)
				{
					isPrime[j] = false;
				}
			}
		}

		for (int i = 2; i <= N; i++)
		{
			if (isPrime[i])
			{
				Primes.push_back(i);
			}
		}

		int p1 = 0;
		int p2 = 0;

		int count = 0;

		while (p1 <= Primes.size() - 1 && p2 <= Primes.size() - 1 && p1 <= p2)
		{
			if (p1 == p2)
			{
				if (Primes[p1] == N)
				{
					count++;

				}
				p2++;
			}
			else
			{
				int sum = 0;

				for (int i = p1; i <= p2; i++)
				{
					sum += Primes[i];
				}

				if (sum == N)
				{
					count++;
					p1++;
					p2++;
				}
				else if (sum > N)
				{
					p1++;
				}
				else
				{
					p2++;
				}
			}
		}

		cout << count;
	}
	else
	{
		cout << 0;
	}

}
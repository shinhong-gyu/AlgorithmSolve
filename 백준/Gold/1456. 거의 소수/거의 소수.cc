#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long A, B;
	cin >> A >> B;

	vector<bool> isPrime(10000001, true);
	vector<int> Primes;

	isPrime[0] = false;
	isPrime[1] = false;

	for (long long i = 2; i <= sqrt(B); i++)
	{
		if (isPrime[i] == true)
		{
			Primes.push_back(i);

			for (long long j = i + i; j <= sqrt(B); j += i)
			{
				isPrime[j] = false;
			}
		}
	}

	int count = 0;

	for (long long i = 0; i < Primes.size(); i++)
	{
		int exp = 2;
		while (pow(Primes[i], exp) <= B)
		{
			if (pow(Primes[i], exp) >= A)
			{
				count++;
			}
			exp++;
		}
	}

	cout << count;
}
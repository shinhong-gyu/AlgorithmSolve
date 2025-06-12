#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define ll long long

vector<bool> isPrime(1001000, true);
vector<int> Primes;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll min, max;
	cin >> min >> max;

	isPrime[0] = false;
	isPrime[1] = false;

	for (int i = 2; i <= sqrt(max); i++)
	{
		if (isPrime[i])
		{
			Primes.push_back(i);
			for (int j = i; j <= sqrt(max); j += i)
			{
				isPrime[j] = false;
			}
		}
	}

	vector<bool> NonPower(max - min + 1, false);

	int count = 0;

	for (int i = 0; i < Primes.size(); i++)
	{
		ll power = pow(Primes[i], 2);

		ll powerMulit = ((min + power - 1) / power) * power;

		while (powerMulit <= max)
		{
			NonPower[powerMulit - min] = true;
			powerMulit += power;
		}
	}

	int total = max - min + 1;

	for (int i = 0; i < NonPower.size(); i++)
	{
		if (NonPower[i])
		{
			--total;

		}
	}

	cout << total - count;

}
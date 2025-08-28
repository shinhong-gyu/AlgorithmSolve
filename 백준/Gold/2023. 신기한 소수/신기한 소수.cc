#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

vector<bool> isPrime;

string prime;
int N;

void solve(int depth)
{
	if (depth > N)
	{
		return;
	}

	if (depth == N)
	{
		int n = stoi(prime);
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
			{
				return;
			}
		}

		cout << n << endl;
	}

	for (int i = 1; i <= 9; i++)
	{
		if (depth == 0 && i == 1)
		{
			continue;
		}


		prime += to_string(i);

		int n = stoi(prime);
		bool isPrime = true;

		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
			{
				isPrime = false;
			}
		}

		if (isPrime)
		{
			solve(depth + 1);
		}

		prime.pop_back();
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	solve(0);
}
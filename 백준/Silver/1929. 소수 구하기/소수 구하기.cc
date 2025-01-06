#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<bool> prime(M + 1, true);

	prime[0] = false;
	prime[1] = false;

	for (int i = 2; i <= sqrt(M); i++)
	{
		if (prime[i] == true)
		{
			for (int j = 2; j * i <= M; j++)
			{
				prime[i * j] = false;
			}
		}
	}
	for (int i = N; i <= M; i++)
	{
		if (prime[i] == true)
		{
			cout << i << "\n";
		}
	}

}
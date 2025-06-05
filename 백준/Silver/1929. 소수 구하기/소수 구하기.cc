#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<bool> isPrime(M + 1, false);
	vector<bool> isModified(M + 1, false);

	for (int i = 2; i <= M; i++)
	{
		if (isPrime[i] == false && isModified[i] == false)
		{
			isPrime[i] = true;
			for (int j = i + i; j <= M; j += i)
			{
				isModified[j] = true;
			}
		}
	}

	for (int i = N; i <= M; i++)
	{
		if (isPrime[i] == true)
		{
			cout << i << '\n';
		}
	}
}
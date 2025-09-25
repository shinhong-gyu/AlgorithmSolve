#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int T[16];
int P[16];

// i일부터 마지막 날까지 얻을 수 있는 최대 이득
int DP[17] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> T[i] >> P[i];
	}

	for (int i = N; i >= 1; i--)
	{
		if (i + T[i] > N + 1)
		{
			DP[i] = DP[i + 1];
		}
		else
		{
			DP[i] = max(DP[i + 1], DP[i + T[i]] + P[i]);
		}
	}

	cout << *max_element(DP, DP + 17);
}
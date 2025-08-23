#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;

	cin >> N >> K;

	vector<int> coins(N);

	// K를 만들 수 있는지 없는지 여부, K를 만들기 위해 필요한 동전의 개수
	vector<int> DP(K + 1, 100001);


	for (int i = 0; i < N; i++)
	{
		cin >> coins[i];
	}

	DP[0] = 0;

	sort(coins.begin(), coins.end());
	coins.erase(unique(coins.begin(), coins.end()), coins.end());

	for (int i = 0; i < coins.size(); i++)
	{
		int cur = coins[i];

		for (int j = cur; j <= K; j++)
		{
			if (DP[j - cur] != 100001)
			{
				DP[j] = min(DP[j], DP[j - cur] + 1);
			}

		}
	}

	if (DP[K] == 100001)
	{
		cout << -1;
	}
	else
	{
		cout << DP[K];
	}
}
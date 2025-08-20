#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;


	vector<int> app(N + 1);
	vector<int> cost(N + 1);

	int total = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> app[i];
	}

	for (int i = 1; i <= N; i++)
	{
		cin >> cost[i];
		total += cost[i];
	}

	vector<int> dp(total + 1, 0);


	for (int i = 1; i <= N; i++)
	{
		for (int j = total; j >= cost[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - cost[i]] + app[i]);
		}
	}

	for (int i = 0; i <= total; i++)
	{
		if (dp[i] >= M)
		{
			cout << i;
			break;
		}
	}
}
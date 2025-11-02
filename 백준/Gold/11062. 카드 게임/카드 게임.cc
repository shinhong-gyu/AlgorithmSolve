#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int N;
vector<int> cards;
vector<vector<int>> dp;

int solve(int l, int r)
{
	if (l > r)
	{
		return 0;
	}

	if (dp[l][r] != -1)
	{
		return dp[l][r];
	}

	int taken = N - (r - l + 1);
	bool turn = taken % 2 == 0;

	if (turn)
	{
		int left = cards[l] + solve(l + 1, r);
		int right = cards[r] + solve(l, r - 1);

		return dp[l][r] = max(left, right);
	}
	else
	{
		int left = solve(l + 1, r);
		int right = solve(l, r - 1);

		return dp[l][r] = min(left, right);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		cin >> N;

		cards.resize(N + 1);
		dp.clear();
		dp.resize(N + 1, vector<int>(N + 1, -1));

		for (int i = 1; i <= N; i++)
		{
			cin >> cards[i];
		}

		cout << solve(1, N) << "\n";
	}
}
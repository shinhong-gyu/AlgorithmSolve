#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int dp[501][501] = { 0 };
int tree[501][501] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;


	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cin >> tree[i][j];
		}
	}


	dp[1][0] = tree[1][0];

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][j] + tree[i][j];
			}
			else if (j == i - 1)
			{
				dp[i][j] = dp[i - 1][j - 1] + tree[i][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tree[i][j];
			}
		}
	}

	cout << *max_element(dp[N], dp[N] + N);
}
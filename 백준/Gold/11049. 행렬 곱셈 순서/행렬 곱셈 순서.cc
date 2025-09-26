#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Matrix
{
	long long row, col;

	long long operator* (const Matrix& m)
	{
		return this->row * this->col * m.col;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<Matrix> m(N);

	vector<vector<long long>> dp(N, vector<long long>(N, 0));

	for (int i = 0; i < N; i++)
	{
		cin >> m[i].row >> m[i].col;
	}

	for (int i = 0; i < N - 1; i++)
	{
		dp[i][i + 1] = m[i] * m[i + 1];
	}

	for (int i = 2; i < N; i++)
	{
		for (int j = 0; j+i < N; j++)
		{
			dp[j][j + i] = LLONG_MAX;

			for (int k = 0; j + k < j + i; k++)
			{
				long long cost = dp[j][j + k] + dp[j + k + 1][j + i] + (m[j].row * m[j + k].col * m[j + i].col);

				dp[j][j + i] = min(dp[j][j + i], cost);
			}
		}
	}

	cout << dp[0][N - 1];
}
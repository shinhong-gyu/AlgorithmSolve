#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Matrix
{
	int row;
	int col;

	int operator* (const Matrix& rhs)
	{
		if (this->row == rhs.col)
		{
			return rhs.col * this->col * rhs.row;
		}
		else
		{
			return rhs.col * this->row * rhs.row;
		}
	}

	Matrix Mul(const Matrix& InMatrix)
	{
		Matrix retMat;

		if (this->row == InMatrix.col)
		{
			retMat.col = this->col;
			retMat.row = InMatrix.row;

			return retMat;
		}
		else
		{
			retMat.row = this->row;
			retMat.col = InMatrix.col;

			return retMat;
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<Matrix> m(N + 1);
	vector<vector<long long>> dp(N + 1, vector<long long>(N + 1,0));

	for (int i = 1; i <= N; i++)
	{
		cin >> m[i].row >> m[i].col;
	}

	for (int i = 1; i < N; i++)
	{
		dp[i][i + 1] = m[i].row * m[i].col * m[i + 1].col;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j + i <= N; j++)
		{
			dp[j][j + i] = LLONG_MAX;

			for (int p = j; p < j + i; p++)
			{
				long long cost = dp[j][p] + dp[p + 1][i + j] + (long long)m[j].row * m[p].col * m[i + j].col;
				dp[j][j + i] = min(dp[j][j + i], cost);
			}
		}
	}

	cout << dp[1][N];
}
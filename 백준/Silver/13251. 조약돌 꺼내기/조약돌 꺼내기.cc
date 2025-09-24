#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int color[51];
int dp[2501][2501];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M;
	cin >> M;

	if (M == 1)
	{
		cout << 1.0f;
		return 0;
	}

	int total = 0;

	for (int i = 0; i < M; i++)
	{
		cin >> color[i];
		total += color[i];
	}

	for (int i = 0; i <= total; i++)
	{
		dp[i][i] = 1;
		dp[i][0] = 1;
		dp[i][1] = i;
	}

	int K;
	cin >> K;

	if (K == 1)
	{
		cout << 1.0f;
		return 0;
	}

	for (int i = 1; i <= total; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	long double totalProb = 0.0;

	for (int i = 0; i < M; i++)
	{
		long double prob = 1.0;
		int count = color[i];
		int tempTotal = total;

		for (int j = 0; j < K; j++)
		{
			prob *= (long double)count / tempTotal;
			count--;
			tempTotal--;
		}

		totalProb += prob;
	}

	cout << fixed << setprecision(15) <<totalProb;
}
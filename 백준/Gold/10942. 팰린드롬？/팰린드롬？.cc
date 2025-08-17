#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	// i부터 j까지의 숫자를 썼을 때 펠린드롬 여부
	vector<vector<bool>> dp(N, vector<bool>(N, false));
	int seq[2001] = { 0 };

	for (int i = 0; i < N; i++)
	{
		cin >> seq[i];

		dp[i][i] = true;
	}

	for (int i = 0; i < N - 1; i++)
	{
		dp[i][i + 1] = (seq[i] == seq[i + 1]);
	}


	for (int l = 3; l <= N; l++) {
		for (int i = 0; i <= N - l; i++) {

			int j = i + l - 1;

			if (seq[i] == seq[j] && dp[i + 1][j - 1]) 
			{
				dp[i][j] = true;
			}
		}
	}

	int M;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int S, E;
		cin >> S >> E;
		cout << dp[S - 1][E - 1] << "\n";
	}
}
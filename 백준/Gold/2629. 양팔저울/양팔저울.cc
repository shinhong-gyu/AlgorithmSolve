#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <algorithm>

using namespace std;

bool dp[15501];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> weight(N);

	for (int i = 0; i < N; i++)
	{
		cin >> weight[i];
	}

	dp[weight[0]] = true;

	for (int i = 1; i < N; i++)
	{
		unordered_set<int> canCheck;
		for (int k = 1; k < 15001; k++)
		{
			if (dp[k])
			{
				canCheck.insert(k + weight[i]);
				canCheck.insert(abs(k - weight[i]));
				canCheck.insert(weight[i]);
			}
		}

		for (int e : canCheck)
		{
			dp[e] = true;
		}
	}


	int M;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int cur;
		cin >> cur;

		if (cur < 15501 && dp[cur])
		{
			cout << "Y\n";
		}
		else
		{
			cout << "N\n";
		}
	}
}
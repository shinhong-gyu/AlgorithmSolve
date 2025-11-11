#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (1)
	{
		int N, M;
		float temp;
		cin >> N >> temp;

		if (N == 0 && temp == 0)
		{
			break;
		}

		M = round(temp * 100);

		vector<int> kcal(N + 1);
		vector<int> price(N + 1);

		for (int i = 1; i <= N; i++)
		{
			cin >> kcal[i] >> temp;
			price[i] = round(temp * 100);
		}

		vector<int> dp(M + 1, 0);

		for (int i = 1; i <= N; i++)
		{
			for (int k = 1; price[i] * k <= M; k++)
			{
				dp[price[i] * k] = kcal[i] * k;
			}
		}


		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (j - price[i] > 0 && dp[j - price[i]] + kcal[i] != 0)
				{
					dp[j] = max(dp[j], dp[j - price[i]] + kcal[i]);
				}
			}
		}

		cout << *max_element(dp.begin(), dp.end()) << "\n";
	}
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;


	vector<int> floor(3);
	vector<int> current_max_dp(3);
	vector<int> current_min_dp(3);
	vector<int> prev_max_dp(3);
	vector<int> prev_min_dp(3);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> floor[j];
		}

		if (i == 0)
		{
			prev_max_dp[0] = floor[0];
			prev_max_dp[1] = floor[1];
			prev_max_dp[2] = floor[2];
			prev_min_dp[0] = floor[0];
			prev_min_dp[1] = floor[1];
			prev_min_dp[2] = floor[2];
			current_max_dp[0] = floor[0];
			current_max_dp[1] = floor[1];
			current_max_dp[2] = floor[2];
			current_min_dp[0] = floor[0];
			current_min_dp[1] = floor[1];
			current_min_dp[2] = floor[2];
		}
		else
		{
			current_max_dp[0] = floor[0] + max(prev_max_dp[0], prev_max_dp[1]);
			current_max_dp[1] = floor[1] + max({ prev_max_dp[0], prev_max_dp[1], prev_max_dp[2] });
			current_max_dp[2] = floor[2] + max(prev_max_dp[1], prev_max_dp[2]);
			current_min_dp[0] = floor[0] + min(prev_min_dp[0], prev_min_dp[1]);
			current_min_dp[1] = floor[1] + min({ prev_min_dp[0],prev_min_dp[1], prev_min_dp[2] });
			current_min_dp[2] = floor[2] + min(prev_min_dp[1], prev_min_dp[2]);

			prev_max_dp[0] = current_max_dp[0];
			prev_max_dp[1] = current_max_dp[1];
			prev_max_dp[2] = current_max_dp[2];
			prev_min_dp[0] = current_min_dp[0];
			prev_min_dp[1] = current_min_dp[1];
			prev_min_dp[2] = current_min_dp[2];
		}
	}


	cout << max({ current_max_dp[0], current_max_dp[1], current_max_dp[2] }) << " ";


	cout << min({ current_min_dp[0],current_min_dp[1], current_min_dp[2] });


}

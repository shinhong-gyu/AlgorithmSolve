#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int SCV[3];
int dp[61][61][61] = { 0 };

struct State
{
	int scv1;
	int scv2;
	int scv3;
};

void sortState(State& s)
{
	if (s.scv1 < s.scv2)
	{
		int temp = s.scv1;
		s.scv1 = s.scv2;
		s.scv2 = temp;
	}

	if (s.scv1 < s.scv3)
	{
		int temp = s.scv1;
		s.scv1 = s.scv3;
		s.scv3 = temp;
	}

	if (s.scv2 < s.scv3)
	{
		int temp = s.scv2;
		s.scv2 = s.scv3;
		s.scv3 = temp;
	}
}

int attacks[6][3] = { {9,3,1},{9,1,3},{1,9,3},{1,3,9},{3,9,1},{3,1,9} };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;


	for (int i = 0; i < N; i++)
	{
		cin >> SCV[i];
	}



	for (int i = 0; i <= 60; i++)
	{
		for (int j = 0; j <= 60; j++)
		{
			for (int k = 0; k <= 60; k++)
			{
				dp[i][j][k] = -1;
			}
		}
	}

	queue<pair<State, int>> q;

	State s = { SCV[0],SCV[1],SCV[2] };

	sortState(s);

	q.push({ s,0 });

	dp[s.scv1][s.scv2][s.scv3] = 0;

	int answer = 10000001;

	while (!q.empty())
	{
		int n = q.front().second;
		State s = q.front().first;

		q.pop();

		if (s.scv1 == 0 && s.scv2 == 0 && s.scv3 == 0)
		{
			answer = min(n, answer);
			continue;
		}


		for (int i = 0; i < 6; i++)
		{
			State temp = s;

			temp.scv1 = max(0, temp.scv1 - attacks[i][0]);
			temp.scv2 = max(0, temp.scv2 - attacks[i][1]);
			temp.scv3 = max(0, temp.scv3 - attacks[i][2]);

			sortState(temp);

			// temp의 조합이 이미 계산한 조합이라면 
			if (dp[temp.scv1][temp.scv2][temp.scv3] != -1)
			{
				//dp[s.scv1][s.scv2][s.scv3] = min(dp[s.scv1][s.scv2][s.scv3], n + 1);
				continue;
			}

			dp[temp.scv1][temp.scv2][temp.scv3] = n + 1;
			q.push({ temp, n + 1 });
		}
	}

	cout << answer;
}
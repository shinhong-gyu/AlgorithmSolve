#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int m[51][51] = { 0 };
int c_count = 0;
int N, M;

vector<pair<int, int>> c_loc;
vector<pair<int, int>> h_loc;

vector<pair<int, int>> aliveC;

int c_dist = INT_MAX;

void solve(int idx)
{
	if (aliveC.size() == M)
	{
		int total = 0;
		for (int i = 0; i < (int)h_loc.size(); i++)
		{
			int minDist = INT_MAX;

			for (int j = 0; j < (int)aliveC.size(); j++)
			{
				if (abs(aliveC[j].first - h_loc[i].first) + abs(aliveC[j].second - h_loc[i].second) < minDist)
				{
					minDist = abs(aliveC[j].first - h_loc[i].first) + abs(aliveC[j].second - h_loc[i].second);
				}
			}
			total += minDist;
		}

		if (total < c_dist)
		{
			c_dist = total;
		}

		return;
	}

	for (int i = idx; i < (int)c_loc.size(); i++)
	{
		aliveC.push_back(c_loc[i]);

		solve(i + 1);

		aliveC.pop_back();
	}

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> m[i][j];

			if (m[i][j] == 2)
			{
				c_count++;
				c_loc.push_back({ i,j });
			}
			else if (m[i][j] == 1)
			{
				h_loc.push_back({ i,j });
			}

		}
	}

	solve(0);

	cout << c_dist;
}
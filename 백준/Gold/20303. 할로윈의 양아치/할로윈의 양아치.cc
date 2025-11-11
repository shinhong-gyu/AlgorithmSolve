#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>

using namespace std;

vector<int> candy;

struct Union
{
	Union(int n)
	{
		parent.resize(n);
		candies.resize(n);

		for (int i = 1; i < candies.size(); i++)
		{
			candies[i].first = candy[i];
			candies[i].second = 1;
		}
		iota(parent.begin(), parent.end(), 0);
	}

	int Find(int n)
	{
		if (n == parent[n])
		{
			return n;
		}

		return parent[n] = Find(parent[n]);
	}

	void SetUnion(int i, int j)
	{
		int root_i = Find(i);
		int root_j = Find(j);

		if (root_i != root_j)
		{
			parent[root_j] = root_i;
			candies[root_i].first += candies[root_j].first;
			candies[root_i].second += candies[root_j].second;
		}
	}

	bool IsUnion(int i, int j)
	{
		return Find(i) == Find(j);
	}

	vector<pair<int, int>> GetGroup()
	{
		unordered_set<int> s;

		for (int i = 1; i < parent.size(); i++)
		{
			s.insert(Find(i));
		}

		vector<pair<int, int>> temp;
		for (auto n : s)
		{
			temp.push_back(candies[n]);
		}

		return temp;
	}

	vector<int> parent;
	vector<pair<int, int>> candies;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, K;

	cin >> N >> M >> K;

	candy.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		cin >> candy[i];
	}

	Union uf(N + 1);

	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;

		uf.SetUnion(A, B);
	}

	vector<pair<int, int>> s = uf.GetGroup();

	vector<vector<int>> dp(s.size(), vector<int>(K, 0));

	for (int i = 1; i < K; i++)
	{
		if (i >= s[0].second)
		{
			dp[0][i] = s[0].first;
		}
	}


	for (int i = 1; i < s.size(); i++)
	{
		for (int j = 0; j < K; j++)
		{
			if (j - s[i].second >= 0)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - s[i].second] + s[i].first);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[s.size() - 1][K - 1];
}
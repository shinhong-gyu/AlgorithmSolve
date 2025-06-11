#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class UnionFind
{
public:
	UnionFind(int n)
	{
		parent.resize(n);

		iota(parent.begin(), parent.end(), 0);

		rank.assign(n, 0);
	}

	int find(int i)
	{
		if (parent[i] == i)
		{
			return i;
		}

		parent[i] = find(parent[i]);

		return parent[i];
	}

	void unionSet(int i, int j)
	{
		int root_i = find(i);
		int root_j = find(j);

		if (root_i != root_j)
		{
			if (rank[root_j] < rank[root_i])
			{
				parent[root_j] = root_i;
			}
			else if (rank[root_j] > rank[root_i])
			{
				parent[root_i] = root_j;
			}
			else
			{
				parent[root_j] = root_i;
				rank[root_j]++;
			}
		}
	}

	bool isUnion(int i, int j)
	{
		int root_i = find(i);
		int root_j = find(j);

		return root_i == root_j;
	}

	vector<int> parent;
	vector<int> rank;

};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N;
	cin >> M;

	vector<int> travelPlan(M);
	UnionFind citys(N+1);

	for (int i = 1; i <= N; i++)
	{
		vector<int> link(N+1);

		for (int j = 1; j <= N; j++)
		{
			cin >> link[j];
		}

		for (int j = 1; j <= N; j++)
		{
			if (link[j] == 1 && i != j)
			{
				citys.unionSet(i, j);
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		cin >> travelPlan[i];
	}

	for (int i = 0; i < M - 1; i++)
	{
		if (!citys.isUnion(travelPlan[i], travelPlan[i + 1]))
		{
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";
}
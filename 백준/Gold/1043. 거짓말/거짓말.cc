#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

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

	cin >> N >> M;

	int truthTellerNum;
	cin >> truthTellerNum;

	vector<bool> truthTeller(N + 1, false);

	UnionFind uf(N + 1);

	for (int i = 1; i <= truthTellerNum; i++)
	{
		int idx;
		cin >> idx;
		truthTeller[idx] = true;
	}

	int first_TruthTeller = find(truthTeller.begin(), truthTeller.end(), true) - truthTeller.begin();
	int first_NonTruthTeller = find(truthTeller.begin(), truthTeller.end(), false) - truthTeller.begin();

	for (int i = 1; i <= N; i++)
	{
		if (first_TruthTeller == truthTeller.size())
		{
			break;
		}

		if (truthTeller[i])
		{
			uf.unionSet(first_TruthTeller, i);
		}
	}

	int GuLaCount = M;
	bool canGuLa = true;

	vector<int> participants[51];


	for (int i = 0; i < M; i++)
	{
		int participant;
		cin >> participant;

		canGuLa = true;

		for (int j = 0; j < participant; j++)
		{
			int temp;
			cin >> temp;

			participants[i].push_back(temp);

			if (first_TruthTeller == truthTeller.size())
			{
				continue;
			}

			if (uf.isUnion(first_TruthTeller, temp))
			{
				canGuLa = false;
			}
		}
		for (int j = 0; j < participants[i].size() - 1; j++)
		{
			int cur = participants[i][j];
			int next = participants[i][j + 1];
			uf.unionSet(cur, next);
		}
	}

	for (int i = 0; i < M; i++)
	{
		if (first_TruthTeller == truthTeller.size())
		{
			break;
		}

		for (int n : participants[i])
		{
			if (uf.isUnion(first_TruthTeller, n))
			{
				GuLaCount--;
				break;
			}
		}
	}

	cout << GuLaCount;
}
#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

struct Edge
{
	int s, e, c;

	bool operator>(const Edge& e) const
	{
		return this->c > e.c;
	}
};

class Union
{
public:
	Union(int n)
	{
		parent.resize(n);
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
		}
	}

	bool IsUnion(int i, int j)
	{
		return Find(i) == Find(j);
	}

	vector<int> parent;
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	priority_queue<Edge, vector<Edge>, greater<Edge>> edges;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int C;
			cin >> C;

			if (j != i)
			{
				edges.push({ i,j, C });
				edges.push({ j,i, C });
			}
		}
	}

	unsigned long long total = 0;
	int count = 0;

	Union uf(N + 1);

	while (!edges.empty() && count < N - 1)
	{
		Edge cur = edges.top();

		edges.pop();

		int s = cur.s;
		int e = cur.e;
		int c = cur.c;

		if (!uf.IsUnion(s, e))
		{
			uf.SetUnion(s, e);
			count++;
			total += c;
		}
	}

	cout << total;
}
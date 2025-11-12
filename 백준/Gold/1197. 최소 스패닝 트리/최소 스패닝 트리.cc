#include <iostream>
#include <vector>
#include <climits>
#include <tuple>
#include <algorithm>
#include <numeric>

using namespace std;
typedef tuple<int, int, int> edge;

class UnionFind
{

public:
	UnionFind(int n)
	{
		parent.resize(n);

		iota(parent.begin(), parent.end(), 0);
	}

	int Find(int i)
	{
		if (parent[i] == i)
		{
			return i;
		}

		parent[i] = Find(parent[i]);

		return parent[i];
	}

	void UnionSet(int i, int j)
	{
		int root_i = Find(i);
		int root_j = Find(j);

		if (i != j)
		{
			parent[root_j] = root_i;
		}
	}

	bool IsUnion(int i, int j)
	{
		int root_i = Find(i);
		int root_j = Find(j);

		return root_i == root_j;
	}

	vector<int> parent;
};

bool Pred(const tuple<int, int, int>& t1, const tuple<int, int, int>& t2)
{
	return get<2>(t1) < get<2>(t2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E;

	cin >> V >> E;

	vector<edge> edges;
	UnionFind uf(V + 1);

	for (int i = 0; i < E; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;

		edges.push_back(make_tuple(a, b, c));
	}

	sort(edges.begin(), edges.end(), Pred);

	long long spanning = 0;
	int count = 0;
	int idx = 0;

	for (const auto& edge : edges)
	{
		if (count == V - 1)
		{
			break;
		}

		int u = get<0>(edge);
		int v = get<1>(edge);
		int weight = get<2>(edge);

		if (uf.Find(u) != uf.Find(v))
		{
			uf.UnionSet(u, v);
			spanning += weight;
			count++;
		}
	}

	cout << spanning;
}
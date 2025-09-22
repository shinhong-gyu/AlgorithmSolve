#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <numeric>
using namespace std;

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

	int N, M;
	cin >> N;
	cin >> M;

	Union uf(2 * N + 1);
	for (int i = 0; i < M; i++)
	{
		char t;
		int p, q;
		cin >> t >> p >> q;

		if (t == 'E')
		{
			uf.SetUnion(p, q + N);
			uf.SetUnion(q, p + N);
		}
		else
		{
			uf.SetUnion(p, q);
		}
	}

	unordered_set<int> s;

	for (int i = 1; i <= N; i++)
	{
		s.insert(uf.Find(i));
	}

	cout << s.size();
}
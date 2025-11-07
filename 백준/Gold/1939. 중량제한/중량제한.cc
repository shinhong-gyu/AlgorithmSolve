#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

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

struct Info
{
	int a, b, c;
};

bool Compare(const Info& i1, const Info& i2)
{
	return i1.c > i2.c;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<Info> bridges(M);

	int maxWeight = -1;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		bridges[i] = { a,b,c };

		maxWeight = max(c, maxWeight);
	}

	sort(bridges.begin(), bridges.end(), Compare);

	int to, from;
	cin >> to >> from;

	Union uf(N + 1);

	int answer;
	for (int i = 0; i < M; i++)
	{
		const Info& info = bridges[i];

		uf.SetUnion(info.a, info.b);

		if (uf.IsUnion(to, from))
		{
			answer = info.c;
			break;
		}
	}

	cout << answer;
}
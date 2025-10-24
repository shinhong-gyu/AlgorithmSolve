#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <numeric>

using namespace std;



struct Info
{
	int s, e, c;
	bool operator> (const Info& t1) const
	{
		return this->c > t1.c;
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
	cin.tie(nullptr);

	while (1)
	{
		int M, N;
		cin >> M >> N;

		if (M == 0 && N == 0)
		{
			break;
		}

		priority_queue<Info, vector<Info>, greater<Info>> edges;

		long long total = 0;
		for (int i = 0; i < N; i++)
		{
			int x, y, z;
			cin >> x >> y >> z;

			edges.push({ x,y,z });
			total += z;
		}

		long long spanning = 0;
		int count = 0;
		Union uf(M + 1);

		while (!edges.empty())
		{
			auto cur = edges.top();
			edges.pop();

			int s = cur.s;
			int c = cur.c;
			int e = cur.e;

			if (!uf.IsUnion(s, e))
			{
				uf.SetUnion(s, e);
				spanning += c;
				count++;
			}

			if (count == N - 1)
			{
				break;
			}
		}

		if (N != M - 1)
		{
			cout << total - spanning << "\n";
		}
		else
		{
			cout << 0 << "\n";
		}
	}


}
#include <iostream>
#include <vector>
#include <tuple>
#include <numeric>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;
using tup = tuple<double, int, int>;

struct Union
{
	vector<int> parent;

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
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<pair<long long, long long>> coordinate(N + 1);

	for (int i = 1; i <= N; i++)
	{
		cin >> coordinate[i].first >> coordinate[i].second;
	}

	priority_queue<tup, vector<tup>, greater<tup>> pq;

	for (int i = 1; i <= N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			long long dx = coordinate[i].first - coordinate[j].first;
			long long dy = coordinate[i].second - coordinate[j].second;
			double dist = sqrt(dx * dx + dy * dy);

			pq.push(make_tuple(dist, i, j));

		}
	}

	int spanning = 0;

	double totalDist = 0.0;

	Union uf(N + 1);

	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;

		uf.SetUnion(A, B);
	}

	while (!pq.empty())
	{
		auto cur = pq.top();
		pq.pop();

		double dist = get<0>(cur);
		int A = get<1>(cur);
		int B = get<2>(cur);

		if (!uf.IsUnion(A, B))
		{
			totalDist += dist;
			uf.SetUnion(A, B);
			spanning++;
		}
	}

	cout << fixed << setprecision(2) << totalDist;
}
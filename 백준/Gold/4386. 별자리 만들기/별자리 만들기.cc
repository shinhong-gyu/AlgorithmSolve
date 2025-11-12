#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <tuple>
#include <numeric>
#include <iomanip>



using namespace std;

using tup = tuple<float, int, int>;

struct Point
{
	float x, y;
};

float distance(const Point& p1, const Point& p2)
{
	return floor(100 * sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y))) / 100;
}

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

	int N;
	cin >> N;

	vector<Point> stars(N);

	for (int i = 0; i < N; i++)
	{
		cin >> stars[i].x >> stars[i].y;
	}

	priority_queue<tup, vector<tup>, greater<tup>> pq;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i != j)
			{
				pq.push(make_tuple(distance(stars[i], stars[j]), i, j));
			}
		}
	}

	Union uf(N + 1);

	int spanning = 0;
	float totalDist = 0;
	while (!pq.empty())
	{
		auto& cur = pq.top();

		pq.pop();

		float dist = get<0>(cur);
		int a = get<1>(cur);
		int b = get<2>(cur);

		if (!uf.IsUnion(a, b))
		{
			uf.SetUnion(a, b);

			totalDist += dist;
			spanning++;
		}

		if (spanning == N - 1)
		{
			break;
		}
	}

	cout << fixed << setprecision(2) << totalDist;
}
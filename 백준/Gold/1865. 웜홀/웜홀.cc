#include <iostream>
#include <vector>
#include <tuple>
#include <climits>


using namespace std;

typedef tuple<int, int, int> Edge;
const int INF = 1e9;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		int N, M, W;

		cin >> N >> M >> W;

		vector<Edge> edges;

		for (int i = 0; i < M; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;

			edges.push_back(make_tuple(a, b, c));
			edges.push_back(make_tuple(b, a, c));
		}


		bool update = false;

		for (int i = 0; i < W; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;

			edges.push_back(make_tuple(a, b, -1 * c));

			if (c != 0 && a == b)
			{
				update = true;
			}
		}

		vector<int> D(N + 1, INF);

		for (int i = 0; i < N - 1; i++)
		{
			for (auto edge : edges)
			{
				int s = get<0>(edge);
				int e = get<1>(edge);
				int c = get<2>(edge);

				if (D[s] == INF)
				{
					D[e] = c;
				}
				else
				{
					D[e] = min(D[e], D[s] + c);
				}
			}
		}

		for (auto edge : edges)
		{
			int s = get<0>(edge);
			int e = get<1>(edge);
			int c = get<2>(edge);


			if (D[e] > D[s] + c)
			{
				update = true;
				break;
			}
		}

		if (update)
		{
			cout << "YES" << "\n";
		}
		else
		{
			cout << "NO" << "\n";
		}
	}
}
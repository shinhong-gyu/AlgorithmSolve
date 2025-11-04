#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int k = (int)ceil(log(N) / log(2));

	vector<pair<int, int>> st((int)pow(2, k + 1), { INT_MAX ,0 });

	int base = pow(2, k);

	for (int i = 0; i < N; i++)
	{
		cin >> st[base + i].first;
		st[base + i].second = i;
	}

	int i = base + N - 1;

	while (i != 1)
	{
		st[i / 2] = min(st[i], st[i / 2]);
		i--;
	}

	int M;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int q;
		cin >> q;

		if (q == 1)
		{
			int a, b;
			cin >> a >> b;

			int target = base + a - 1;

			st[target].first = b;

			int i = target;

			while (i != 1)
			{
				if (i % 2 == 1)
				{
					st[i / 2] = min(st[i], st[i - 1]);
				}
				else
				{
					st[i / 2] = min(st[i], st[i + 1]);
				}
				i /= 2;
			}
		}
		else
		{
			cout << st[1].second + 1 << "\n";
		}
	}
}
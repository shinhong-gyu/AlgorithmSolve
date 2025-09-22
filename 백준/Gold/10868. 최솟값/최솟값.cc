#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N >> M;

	int k = ceil(log(N) / log(2));

	vector<int> st(pow(2, k + 1), INT_MAX);

	int base = pow(2, k);

	for (int i = 0; i < N; i++)
	{
		cin >> st[i + base];
	}

	int i = base * 2 - 1;

	while (i > 1)
	{
		st[i / 2] = min(st[i / 2], st[i]);

		i--;
	}

	while (M--)
	{
		int a, b;
		cin >> a >> b;

		int start = base + a - 1;
		int end = base + b - 1;

		int minValue = min(st[start], st[end]);

		while (start <= end)
		{
			minValue = min(minValue, min(st[start], st[end]));

			start = (start + 1) / 2;
			end = (end - 1) / 2;
		}

		cout << minValue << "\n";
	}
}
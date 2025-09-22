#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	long long k = ceil((double)log(N) / log(2));

	vector<long long> st((long long)pow(2, k + 1), 0);

	long long base = pow(2, k);
	long long end = base + N - 1;

	for (int i = 0; i < N; i++)
	{
		long long temp;
		cin >> temp;

		st[base + i] = temp;
	}

	int i = (int)pow(2, k + 1) - 1;
	while (i != 1)
	{
		st[i / 2] += st[i];
		i--;
	}

	int oper = M + K;

	while (oper--)
	{
		long long a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
		{
			long long origin = st[base + b - 1];
			long long delta = c - origin;

			st[base + b - 1] = c;

			long long s = base + b - 1;
			while (s != 1)
			{
				s /= 2;
				st[s] += delta;
			}
		}
		else
		{
			long long start_idx = base + b - 1;
			long long end_idx = base + c - 1;

			long long result = 0;

			while (start_idx <= end_idx)
			{
				if (start_idx % 2 == 1)
				{
					result += st[start_idx];
				}

				if (end_idx % 2 == 0)
				{
					result += st[end_idx];
				}

				start_idx = (start_idx + 1) / 2;
				end_idx = (end_idx - 1) / 2;
			}

			cout << result << '\n';
		}

	}
}

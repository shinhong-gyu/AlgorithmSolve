#include <iostream>

using namespace std;

int N, Q;
long fac[21], seq[21];
bool use[21] = { false };


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	fac[0] = 1;

	for (int i = 1; i <= N; i++)
	{
		fac[i] = fac[i-1] * i;
	}

	cin >> Q;

	if (Q == 1)
	{
		long K;
		cin >> K;

		for (int i = 1; i <= N; i++)
		{
			int count = 1;
			for (int j = 1; j <= N; j++)
			{
				if (use[j])
				{
					continue;
				}

				if (K <= count * fac[N - i])
				{
					K -= ((count - 1) * fac[N - i]);
					seq[i] = j;
					use[j] = true;
					break;
				}
				count++;
			}
		}

		for (int i = 1; i <= N; i++)
		{
			cout << seq[i] << " ";
		}
	}
	else
	{
		long K = 1;

		for (int i = 1; i <= N; i++)
		{
			cin >> seq[i];
			long count = 0;

			for (int j = 1; j < seq[i]; j++)
			{
				if (!use[j])
				{
					count++;
				}
			}

			K += count * fac[N - i];
			use[seq[i]] = true;
		}

		cout << K;
	}
}
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> num(N);
	vector<int> negIdx;

	for (int i = 0; i < N; i++)
	{
		cin >> num[i];

		if (num[i] < 0)
		{
			negIdx.push_back(i);
		}
	}

	vector<int> L(N);
	vector<int> R(N);

	L[0] = num[0];
	R[0] = num[N - 1];
	int maxValue = max(L[0], R[0]);

	for (int i = 1; i < N; i++)
	{
		L[i] = max(num[i], L[i - 1] + num[i]);
		R[i] = max(num[N - i - 1], R[i - 1] + num[N - i - 1]);

		maxValue = max(maxValue,max(L[i], R[i]));
	}

	for (int idx : negIdx)
	{
		if (idx > 0 && idx < N - 1)
		{
			maxValue = max(maxValue, L[idx - 1] + R[N - 1 - idx -1]);
		}
	}

	cout << maxValue;
}
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

	int k = (int)ceil(log(N) / log(2));

	vector<int> maxST((int)pow(2, k + 1), -1);
	vector<int> minST((int)pow(2, k + 1), INT_MAX);

	int base = (int)pow(2, k);

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		minST[base + i] = temp;
		maxST[base + i] = temp;
	}

	int i = (int)pow(2, k + 1) - 1;

	while (i > 1)
	{
		maxST[i / 2] = max(maxST[i / 2], maxST[i]);
		minST[i / 2] = min(minST[i / 2], minST[i]);

		i--;
	}

	while (M--)
	{
		int s, e;
		cin >> s >> e;

		int start = base + s - 1;
		int end = base + e - 1;

		int minValue = INT_MAX;
		int maxValue = -1;
		while (start <= end)
		{
			minValue = min(minValue, min(minST[start], minST[end]));
			maxValue = max(maxValue, max(maxST[start], maxST[end]));

			start = (start + 1) / 2;
			end = (end - 1) / 2;
		}

		cout << minValue << " " << maxValue << "\n";
	}
}
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, B;
	cin >> N >> M >> B;

	vector<vector<int>> ground(N + 1, vector<int>(M + 1));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> ground[i][j];
		}
	}

	int minTime = 2147483647;
	int minHeight = 0;
	for (int targetHeight = 0; targetHeight < 257; targetHeight++)
	{
		int time = 0;
		int block = B;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				int curHeight = ground[i][j];
				if (curHeight < targetHeight)
				{
					int gap = targetHeight - curHeight;
					block -= gap;
					time += gap;
				}
				else if (curHeight > targetHeight)
				{
					int gap = curHeight - targetHeight;

					time += gap * 2;
					block += gap;
				}
			}
		}

		if (block < 0)
		{
			continue;
		}

		if (time <= minTime)
		{
			minTime = time;
			minHeight = targetHeight;
		}
	}

	cout << minTime << " " << minHeight;
}
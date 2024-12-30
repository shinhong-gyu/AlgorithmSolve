#include <iostream>
#include "vector"

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int T;
	cin >> T;


	for (int r = 0; r < T; r++)
	{
		int k, n;
		cin >> k >> n;

		vector<vector<int>> floors(k + 1, vector<int>(n, 0));

		for (int i = 1; i <= n; i++)
		{
			floors[0][i - 1] = i;
		}

		for (int i = 1; i <= k; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int l = 0; l <= j; l++)
				{
					floors[i][j] += floors[i - 1][l];
				}
			}
		}
		cout << floors[k][n - 1] << endl;
	}
}
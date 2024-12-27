#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int S[1025][1025] = {};

	for (int k = 1; k <= N; k++)
	{
		for (int l = 1; l <= N; l++)
		{
			int temp;
			cin >> temp;

			S[k][l] = S[k][l - 1] + S[k - 1][l] - S[k - 1][l - 1] + temp;
		}
	}

	for (int k = 0; k < M; k++)
	{
        int  x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << S[x2][y2] - S[x2][y1-1] - S[x1-1][y2] + S[x1 - 1][y1 - 1] << "\n";
	}
}
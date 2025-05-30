#include <iostream>

int link[101][101] = { 0 };
int canGo[101][101] = { 0 };

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int temp;
			cin >> temp;

			if (temp == 1)
			{
				link[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (link[i][j] == 1 && link[j][k] == 1)
				{
					link[i][k] = 1;
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (link[i][j] == 1 && link[j][k] == 1)
				{
					link[i][k] = 1;
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << link[i][j] << " ";
		}
		cout << "\n";
	}
}
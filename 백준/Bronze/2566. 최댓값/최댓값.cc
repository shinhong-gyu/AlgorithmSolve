#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[9][9];

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> arr[i][j];
		}
	}

	int r, c;
	int answer = -1;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] > answer)
			{
				answer = arr[i][j];
				r = i + 1;
				c = j + 1;
			}
		}
	}

	cout << answer << "\n";
	cout << r << " " << c;

}
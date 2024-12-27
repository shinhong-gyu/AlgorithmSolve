#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int scores[8];

	for (int i = 0; i < 8; i++)
	{
		cin >> scores[i];
	}


	if (scores[0] == 1)
	{
		for (int i = 0; i < 7; i++)
		{
			if (scores[i + 1] - scores[i] != 1)
			{
				cout << "mixed" << endl;
				return 0;
			}
		}
		cout << "ascending" << endl;
	}
	else if (scores[0] == 8)
	{
		for (int i = 0; i < 7; i++)
		{
			if (scores[i] - scores[i + 1] != 1)
			{
				cout << "mixed" << endl;
				return 0;
			}
		}
		cout << "descending" << endl;
	}
	else
	{
		cout << "mixed" << endl;
	}
}
#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,-1,0,1 };

	vector<int> arr;

	int maxLength = -1;

	for (int r = r1; r <= r2; r++)
	{
		for (int c = c1; c <= c2; c++)
		{
			int i = max(abs(r), abs(c));

			int iMax = (int)pow(2 * i + 1, 2);

			int target = iMax;

			int start_x = (2 * i + 1) / 2;
			int start_y = (2 * i + 1) / 2;

			bool stop = false;

			for (int d = 0; d < 4; d++)
			{
				for (int k = 1; k < 2 * i + 1; k++)
				{
					if (start_x == c && start_y == r)
					{
						stop = true;
						break;
					}

					start_x += dx[d];
					start_y += dy[d];
					target--;
				}

				if (stop)
				{
					break;
				}
			}

			maxLength = max(maxLength, (int)to_string(target).length());
			arr.push_back(target);
			//cout << target << " ";
		}

		//cout << '\n';
	}

	

	int count = 0;
	for (int n : arr)
	{
		cout.width(maxLength);
		cout << n << " ";
		count++;


		if (count > c2 - c1)
		{
			cout << "\n";
			count = 0;
		}
	}
}

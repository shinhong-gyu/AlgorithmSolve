#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> crane(N + 1);


	for (int i = 1; i <= N; i++)
	{
		cin >> crane[i];
	}

	int M;
	cin >> M;

	vector<int> box(M);

	for (int i = 0; i <M; i++)
	{
		cin >> box[i];
	}

	sort(box.begin(), box.end());
	sort(crane.begin(), crane.end());

	int count = 0;
	while (!box.empty())
	{
		int prevSize = box.size();
		count++;
		for (int i = 1; i <= N; i++)
		{
			vector<int>::const_iterator iter = upper_bound(box.begin(), box.end(), crane[i]);

			if (iter == box.begin())
			{
				continue;
			}

			box.erase(iter - 1);
		}

		if (prevSize == box.size())
		{
			cout << -1;
			return 0;
		}
	}

	cout << count;

}
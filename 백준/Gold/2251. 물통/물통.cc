#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

bool check[201][201];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> BucketVolumes(3);
	vector<int> curBuckets(3);
	set<int> result;

	int from[6] = { 2,0,1,2,1,0 };
	int to[6] = { 0,1,2,1,0,2 };

	cin >> BucketVolumes[0] >> BucketVolumes[1] >> BucketVolumes[2];

	int maxVolume = BucketVolumes[2];
	curBuckets[2] = maxVolume;
	check[curBuckets[0]][curBuckets[1]] = true;

	queue<pair<int, int>> q;

	q.push(make_pair(0, 0));

	while (!q.empty())
	{
		int a = q.front().first;
		int b = q.front().second;
		int c = maxVolume - a - b;

		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int cur[3] = { a,b,c };

			cur[to[i]] += cur[from[i]];
			cur[from[i]] = 0;

			if (cur[to[i]] > BucketVolumes[to[i]])
			{
				cur[from[i]] = cur[to[i]] - BucketVolumes[to[i]];
				cur[to[i]] = BucketVolumes[to[i]];
			}

			if (cur[0] == 0)
			{
				result.insert(cur[2]);
			}

			if (!check[cur[0]][cur[1]])
			{
				q.push(make_pair(cur[0], cur[1]));
				check[cur[0]][cur[1]] = 1;
			}
		}
	}


	for (auto volume : result)
	{
		cout << volume << " ";
	}
}
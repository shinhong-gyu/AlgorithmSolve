#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int,vector<int>,greater<int>> pq;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int temp;
			cin >> temp;

			if (pq.size() < N)
			{
				pq.push(temp);
			}
			else
			{
				if (temp > pq.top())
				{
					pq.pop();
					pq.push(temp);
				}
			}

		}
	}

	cout << pq.top();
}
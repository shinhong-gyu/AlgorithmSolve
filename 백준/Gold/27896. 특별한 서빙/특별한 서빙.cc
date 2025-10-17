#include <iostream>
#include <queue>
#include <vector>


using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	cin.tie(NULL);

	priority_queue<int> pq;



	int N, M;

	cin >> N >> M;

	vector<int> level(N);

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		level[i] = temp;
	}

	int accum = 0;
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		pq.push(level[i]);

		if (accum + level[i] >= M)
		{
			accum += level[i];
			accum -= pq.top() * 2;
			pq.pop();
			count++;
		}
		else
		{
			accum += level[i];
		}
	}

	cout << count;
}
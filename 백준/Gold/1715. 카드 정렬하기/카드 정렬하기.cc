#include <iostream>
#include <queue>
#include <vector>
#include <functional> 

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int,vector<int>,greater<int>> pq;

	vector<int> sortCount;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		pq.push(temp);
	}

	if (N == 1)
	{
		cout << 0;
		return 0;
	}

	int tempSum = 0;
	int count = 0;

	while (!pq.empty())
	{
		int pqTop = pq.top();

		pq.pop();

		tempSum += pqTop;
		count++;

		if (count >= 2)
		{
			pq.push(tempSum);
			sortCount.push_back(tempSum);
			tempSum = 0;
			count = 0;
		}
	}

	int answer =0;

	for (auto n : sortCount)
	{
		answer+= n;
	}

	cout << answer;
}

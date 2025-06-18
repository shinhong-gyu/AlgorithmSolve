#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		int K;
		cin >> K;

		priority_queue<int> max_pq;
		priority_queue<int, vector<int>, greater<int>> min_pq; 
		map<int, int> counts; 

		for (int i = 0; i < K; i++) 
		{
			char oper;
			int n;
			cin >> oper >> n;

			if (oper == 'I')
			{
				max_pq.push(n);
				min_pq.push(n);
				counts[n]++; 
			}
			else 
			{
				if (counts.empty())
				{
					continue;
				}

				if (n == 1) 
				{ 
					while (!max_pq.empty() && counts[max_pq.top()] == 0) 
					{
						max_pq.pop();
					}
					if (!max_pq.empty()) {
						counts[max_pq.top()]--;
						max_pq.pop();
					}
				}
				else 
				{
					while (!min_pq.empty() && counts[min_pq.top()] == 0) 
					{
						min_pq.pop();
					}
					if (!min_pq.empty()) 
					{
						counts[min_pq.top()]--;
						min_pq.pop();
					}
				}
			}
		}

		while (!max_pq.empty() && counts[max_pq.top()] == 0) 
		{
			max_pq.pop();
		}
		while (!min_pq.empty() && counts[min_pq.top()] == 0) 
		{
			min_pq.pop();
		}

		if (max_pq.empty() || min_pq.empty())
		{
			cout << "EMPTY" << '\n';
		}
		else
		{
			cout << max_pq.top() << ' ' << min_pq.top() << '\n';
		}
	}

	return 0;
}
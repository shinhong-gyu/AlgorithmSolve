#include <iostream>
#include <vector>
#include <cmath>
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

		priority_queue<int> maxpq;
		priority_queue<int, vector<int>, greater<int>> minpq;
		map<int, int> m;

		for (int i = 0; i < K; i++)
		{
			char oper;
			int n;

			cin >> oper >> n;

			if (oper == 'I')
			{
				minpq.push(n);
				maxpq.push(n);
				m[n]++;
			}
			else
			{
				if (m.empty())
				{
					continue;
				}


				if (n == -1)
				{
					while (!minpq.empty() && m[minpq.top()] == 0)
					{
						minpq.pop();
					}
					if (!minpq.empty())
					{
						m[minpq.top()]--;
						minpq.pop();
					}
				}
				else
				{
					while (!maxpq.empty() && m[maxpq.top()] == 0)
					{
						maxpq.pop();
					}
					if (!maxpq.empty())
					{
						m[maxpq.top()]--;
						maxpq.pop();
					}
				}
			}
		}

		while (!minpq.empty() && m[minpq.top()] == 0)
		{
			minpq.pop();
		}

		while (!maxpq.empty() && m[maxpq.top()] == 0)
		{
			maxpq.pop();
		}

		if (minpq.empty() || maxpq.empty())
		{
			cout << "EMPTY" << '\n';
			continue;
		}

		cout << maxpq.top() << ' ' << minpq.top() << '\n';
	}
}



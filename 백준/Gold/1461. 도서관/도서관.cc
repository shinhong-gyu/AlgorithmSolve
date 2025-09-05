#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	priority_queue<int> plusPQ;
	priority_queue<int> minusPQ;

	bool plus = false;

	int answer = 0;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		if (temp < 0)
		{
			minusPQ.push(abs(temp));
		}
		else
		{
			plusPQ.push(temp);
		}
	}
	if (!plusPQ.empty() && !minusPQ.empty())
	{
		plus = plusPQ.top() > minusPQ.top();
	}
	else
	{
		plus = !plusPQ.empty();
	}



	int take = M;
	if (plus)
	{
		int first = plusPQ.top();

		for (int i = 0; i < take; i++)
		{
			plusPQ.pop();

			if (plusPQ.empty())
			{
				break;
			}
		}

		answer += first;
	}
	else
	{
		int first = minusPQ.top();

		for (int i = 0; i < take; i++)
		{
			minusPQ.pop();

			if (minusPQ.empty())
			{
				break;
			}
		}

		answer += first;
	}

	while (plusPQ.size() > 1)
	{
		int first = plusPQ.top();

		for (int i = 0; i < take; i++)
		{
			plusPQ.pop();

			if (plusPQ.empty())
			{
				break;
			}
		}

		answer += first * 2;
	}

	if (plusPQ.size() != 0)
	{
		answer += 2 * plusPQ.top();

		while (!plusPQ.empty())
		{
			plusPQ.pop();
		}
	}


	while (minusPQ.size() >= take)
	{
		int first = minusPQ.top();

		for (int i = 0; i < take; i++)
		{
			minusPQ.pop();

			if (minusPQ.empty())
			{
				break;
			}
		}

		answer += first * 2;
	}

	if (minusPQ.size() != 0)
	{
		answer += 2 * minusPQ.top();

		while (!minusPQ.empty())
		{
			minusPQ.pop();
		}
	}

	cout << answer;
}
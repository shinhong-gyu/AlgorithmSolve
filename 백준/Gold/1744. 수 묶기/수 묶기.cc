#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	priority_queue<int> plusPQ;
	priority_queue<int, vector<int>, greater<int>> minusPQ;

	int one = 0;
	int zero = 0;

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		if (num > 1)
		{
			plusPQ.push(num);
		}
		else if (num < 0)
		{
			minusPQ.push(num);
		}
		else if (num == 1)
		{
			one++;
		}
		else
		{
			zero++;
		}
	}

	while (plusPQ.size() > 1)
	{
		int first = plusPQ.top();
		plusPQ.pop();

		int second = plusPQ.top();
		plusPQ.pop();

		answer += (first * second);
	}

	if (plusPQ.size() == 1)
	{
		answer += plusPQ.top();
	}

	while (minusPQ.size() > 1)
	{
		int first = minusPQ.top();
		minusPQ.pop();

		int second = minusPQ.top();
		minusPQ.pop();

		answer += (first * second);
	}

	if (minusPQ.size() == 1)
	{
		if (zero > 0)
		{
			zero--;
		}
		else
		{
			answer += minusPQ.top();
		}
	}

	answer += one;

	cout << answer;
}
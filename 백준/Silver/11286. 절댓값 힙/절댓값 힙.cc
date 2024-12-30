#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

struct Compare
{
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b)) return a > b;
		return abs(a) > abs(b);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int, vector<int>, Compare> q;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		if (x == 0)
		{
			if (q.empty()) cout << 0 << endl;
			else
			{
				cout << q.top() << endl;
				q.pop();
			}
		}
		else
		{
			q.push(x);
		}
	}
}
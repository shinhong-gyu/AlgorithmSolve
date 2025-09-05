#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	string num;
	cin >> num;

	stack<int> s;
	s.push(num[0] - '0');

	for (int i = 1; i < N; i++)
	{
		int n = num[i] - '0';

		while (K > 0 && !s.empty() && s.top() < n)
		{
			s.pop();
			K--;
		}

		s.push(n);
	}

	while (K > 0)
	{
		s.pop();
        K--;
	}

	vector<int> v;
	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}

	for (int i = v.size() - 1; i >= 0; i--)
	{
		cout << v[i];
	}
}
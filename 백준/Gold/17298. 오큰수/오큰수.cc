#include <stack>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(true);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<int> s;
	vector<int> v;


	int N;
	int temp;

	cin >> N;

	vector<int> answer(N);

	for (int i = 0; i < N; i++)
	{
		cin >> temp;

		v.push_back(temp);
	}

	for (int i = 0; i < N; i++)
	{
		while (!s.empty() && v[i] > v[s.top()])
		{
			answer[s.top()] = v[i];
			s.pop();
		}

		s.push(i);
	}

	while (!s.empty())
	{
		answer[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; answer.size() > i; i++)
	{
		cout << answer[i] << "\n";
	}
}
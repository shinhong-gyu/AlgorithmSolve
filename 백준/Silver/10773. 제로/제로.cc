#include <iostream>
#include <stack>
#include <numeric>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	stack<int> s;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		if (!s.empty() && temp == 0)
		{
			s.pop();
		}
		else
		{
			s.push(temp);
		}
	}

	int sum = 0;
	int size = s.size();
	for (int i = 0; i < size; i++)
	{
		sum += s.top();
		s.pop();
	}

	cout << sum << endl;
}
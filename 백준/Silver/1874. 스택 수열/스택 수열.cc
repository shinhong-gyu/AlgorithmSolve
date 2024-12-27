#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> A(N, 0);
	vector<char> result;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	int temp = 1;
	stack<int> S;
	bool bCan = true;

	for (int i = 0; i < A.size(); i++)
	{
		int su = A[i];
		if (temp <= su)
		{
			while (temp <= su)
			{
				S.push(temp++);
				result.push_back('+');
			}
			S.pop();
			result.push_back('-');
		}
		else
		{
			if (!S.empty())
			{
				int n = S.top();
				S.pop();

				if (n > su)
				{
					cout << "NO";
					bCan = false;
					break;
				}
				else
				{
					result.push_back('-');
				}
			}
		}
	}
	if (bCan)
	{
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << '\n';
		}
	}
}
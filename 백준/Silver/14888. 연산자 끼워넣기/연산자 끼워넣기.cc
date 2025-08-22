#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

vector<int> oper(4);
vector<int> numArr;
int N;

int minAnswer = INT_MAX;
int maxAnswer = INT_MIN;

void solve(int idx, int m)
{
	int cur = m;

	if (idx >= N)
	{
		if (cur < minAnswer)
		{
			minAnswer = cur;
		}

		if (cur > maxAnswer)
		{
			maxAnswer = cur;
		}

		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (oper[i] <= 0)
		{
			continue;
		}

		oper[i]--;

		switch (i)
		{
		case 0:
			cur += numArr[idx];
			break;

		case 1:
			cur -= numArr[idx];
			break;

		case 2:
			cur *= numArr[idx];
			break;

		case 3:
			cur /= numArr[idx];
			break;
		}

		solve(idx + 1, cur);

		oper[i]++;

		switch (i)
		{
		case 0:
			cur -= numArr[idx];
			break;

		case 1:
			cur += numArr[idx];
			break;

		case 2:
			cur /= numArr[idx];
			break;

		case 3:
			cur *= numArr[idx];
			break;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	numArr.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> numArr[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> oper[i];
	}

	solve(1, numArr[0]);

	cout << maxAnswer << "\n";
	cout << minAnswer;
}
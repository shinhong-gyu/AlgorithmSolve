#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int check[100001] = { 0 };

int main()
{
	int N, K;
	cin >> N >> K;

	queue<pair<int, int>> q;
	int temp = N;
	check[N] = 1;
	q.push({ temp,0 });
	int count = 0;
	int depth = 0;
	;
	while (temp != K)
	{
		temp = q.front().first;
		depth = q.front().second;
		q.pop();

		if (temp + 1 == K || temp - 1 == K || temp * 2 == K)
		{
			depth++;
			break;
		}


		if (temp + 1 <= 100000 && check[temp + 1] != 1)
		{
			q.push({ temp + 1,depth + 1 });
			check[temp + 1] = 1;
		}
		if (temp -1 >= 0 &&check[temp - 1] != 1)
		{
			q.push({ temp - 1,depth + 1 });
			check[temp - 1] = 1;
		}
		if (temp * 2 <= 100000 && check[temp * 2] != 1)
		{
			q.push({ temp * 2 ,depth + 1 });
			check[temp * 2] = 1;
		}
	}
	cout << depth << endl;
}
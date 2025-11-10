#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int A, B;

string BFS()
{
	vector<int> visited(10000, false);

	queue<pair<int, string>> q;

	q.push({ A,"" });
	visited[A] = true;

	while (!q.empty())
	{
		int cur = q.front().first;
		string DSLR = q.front().second;

		if (cur == B)
		{
			return DSLR;
		}
		q.pop();

		int D = (cur * 2) % 10000;
		int S = cur == 0 ? 9999 : cur - 1;

		int temp = cur * 10;
		int d1 = temp / 10000;
		temp %= 10000;
		temp += d1;

		int L = temp;

		temp = cur / 10;
		int d4 = cur % 10;

		temp += (d4 * 1000);

		int R = temp;

		if (!visited[D])
		{
			visited[D] = true;
			q.push({ D,DSLR + 'D' });
		}


		if (!visited[S])
		{
			visited[S] = true;
			q.push({ S,DSLR + 'S' });
		}

		if (!visited[L])
		{
			visited[L] = true;
			q.push({ L,DSLR + 'L' });
		}

		if (!visited[R])
		{
			visited[R] = true;
			q.push({ R,DSLR + 'R' });
		}
	}
	return string();
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		cin >> A >> B;

		cout << BFS() << "\n";
	}
}
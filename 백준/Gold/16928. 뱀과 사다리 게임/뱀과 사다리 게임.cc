#include <iostream>
#include <queue>
#include <algorithm>


using namespace std;

int board[101] = { 0 };
bool visited[101] = { false };

int FinalDestination(int pos)
{
	if (board[pos] != 0)
	{
		//cout << pos << "->" << board[pos];
		pos = board[pos];
	}
	else
	{
		//cout << endl;
		return pos;
	}

	return FinalDestination(pos);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;



	for (int i = 0; i < N + M; i++)
	{
		int idx = 0;
		cin >> idx;
		cin >> board[idx];
	}

	queue<pair<int, int>> q;

	int minimam[101] = { 0 };

	q.push(make_pair(1, 0));

	while (!q.empty())
	{
		int cur = q.front().first;
		int count = q.front().second;

		q.pop();


		if (minimam[cur] != 0)
		{
			minimam[cur] = min(count, minimam[cur]);
		}
		else
		{
			minimam[cur] = count;
		}

		int max = -1;

		for (int i = 1; i <= 6; i++)
		{
			if (cur + i <= 100)
			{
				if (!visited[cur + i])
				{
					int pos = FinalDestination(cur + i);

					if (!visited[pos])
					{
						q.push(make_pair(pos, count + 1));
						visited[pos] = true;
					}
				}
			}
		}
	}

	cout << minimam[100];
}
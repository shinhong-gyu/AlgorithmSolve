#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool arr[101][101] = { false };


int bfs(int N)
{
	// i 번째 사람의 kevin bacon 수 계산
	int minKBCount = 2147483647;
	int minUser = 0;

	for (int i = 1; i <= N; i++)
	{
		int kbCount = 0;

		// i 번째 사람과 j번째 사람의 단계 구하기
		for (int j = 1; j <= N; j++)
		{
			queue<pair<int, int>> q;

			if (j == i)
			{
				continue;
			}

			int depth = 0;
			bool visited[101] = { false };

			q.push(make_pair(i, depth));
			visited[i] = true;

			while (!q.empty())
			{
				int cur = q.front().first;
				int curDepth = q.front().second;

				if (cur == j)
				{
					kbCount += curDepth;
					break;
				}

				q.pop();

				for (int k = 1; k <= N; k++)
				{
					if (arr[cur][k] == true && visited[k] != true)
					{
						q.push(make_pair(k, curDepth + 1));
						visited[k] = true;
					} 
				}
			}
		}

		if (kbCount < minKBCount)
		{
			minKBCount = kbCount;
			minUser = i;
		}
	}
	return minUser;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N >> M;

	int a, b;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		arr[a][b] = true;
		arr[b][a] = true;
	}

	cout << bfs(N);
}


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>


using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<vector<int>> edges(N + 1, vector<int>());

	for (int i = 1; i <= N - 1; i++)
	{
		int a, b;

		cin >> a >> b;

		
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	unordered_map<int, int> nodeInfo;
	queue<int> q;

	bool visited[100001] = { false };


	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			q.push(i);

			visited[i] = true;

			while (!q.empty())
			{
				int node = q.front();

				q.pop();

				// node와 연결된 다른 노드가 들어있는 배열을 가져와서
				vector<int> cur = edges[node];

				// 하나 씩 꺼냄
				for (auto num : cur)
				{
					// n = 연결되어있는 노드
					// n이 부모가 있으면 node가 자식으로 들어가고
					// 없으면 node의 자식으로 들어간다

					// 있으면
					if (nodeInfo.find(num) != nodeInfo.end())
					{
						nodeInfo[node] = num;
					}
					else
					{
						nodeInfo[num] = node;
					}

					if (!visited[num])
					{
						q.push(num);
						visited[num] = true;
					}
				}
			}
		}
	}


	for (int i = 2; i <= N; i++)
	{
		cout << nodeInfo[i] << '\n';
	}
}
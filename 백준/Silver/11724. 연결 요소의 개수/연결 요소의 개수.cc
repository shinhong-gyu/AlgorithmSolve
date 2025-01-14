#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// 간선을 사용했는지 체크
int arr[1001][1001] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> link(M, vector<int>(2));

	vector<int> vertex(N + 1, 0);

	stack<int> s;

	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	int count = 0;
	vertex[0] = 1;

	while (find(vertex.begin(), vertex.end(), 0) != vertex.end())
	{
		int idx = find(vertex.begin(), vertex.end(), 0) - vertex.begin();
		count++;
		vertex[idx] = 1;
		s.push(idx);
		while (!s.empty())
		{
			int a = s.top();
			s.pop();
			for (int i = 1; i <= N; i++)
			{
				if (arr[a][i] == 1 && vertex[i] != 1)
				{
					s.push(i);
					vertex[i] = 1;
				}
			}
		}
	}
	cout << count << '\n';
}
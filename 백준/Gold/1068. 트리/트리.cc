#include <iostream>
#include <queue>
#include <string>
#include <numeric>
#include <algorithm>
#include <vector>
#include <cctype>
#include <map>

using namespace std;

vector<vector<int>> treeInfo;
vector<bool> visited;
vector<int> parentInfo;

int DFS(int n)
{
	int ret = 0;

	if (treeInfo[n].size() == 0)
	{
		return 1;
	}

	for (int c : treeInfo[n])
	{
		if (!visited[c])
		{
			ret += DFS(c);
			visited[c] = true;
		}
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	treeInfo.resize(N);
	parentInfo.resize(N);
	visited.resize(N, false);

	int parent = 0;

	for (int i = 0; i < N; i++)
	{
		int p;
		cin >> p;

		parentInfo[i] = p;

		if (p == -1)
		{
			parent = i;
			continue;
		}

		treeInfo[p].push_back(i);
	}

	int r;
	cin >> r;

	if (r == parent)
	{
		cout << 0;
		return 0;
	}

	// 부모 -> 자식
	treeInfo[parentInfo[r]].erase(find(treeInfo[parentInfo[r]].begin(), treeInfo[parentInfo[r]].end(), r));

	int removeLeaf = DFS(parent);

	cout << removeLeaf;
}
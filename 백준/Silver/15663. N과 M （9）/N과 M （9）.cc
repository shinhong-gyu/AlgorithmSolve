#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;


vector<int> arr;
vector<int> seq;
bool visited[9] = { false };
int N, M;

void DFS(int k)
{
	if (k == M)
	{
		for (auto n : seq)
		{
			cout << n << ' ';
		}
		cout << '\n';

		return;
	}

	int pre = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		if (!visited[i])
		{
			if (pre == arr[i])
			{
				continue;
			}

			visited[i] = true;
			pre = arr[i];

			seq.push_back(arr[i]);

			DFS(k + 1);

			seq.pop_back();
			visited[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	arr.resize(N);
	seq.reserve(M);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	DFS(0);
}
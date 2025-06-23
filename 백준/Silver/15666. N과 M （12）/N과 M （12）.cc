#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> seq;
vector<int> input;


void DFS(int k)
{
	if (k == M)
	{
		for (auto n : seq)
		{
			cout << n << ' ';
		}

		cout << endl;
		return;
	}

	bool visited[10001] = { false };

	for (int i = 0; i < input.size(); i++)
	{
		if (!visited[input[i]])
		{
			if (seq.size() != 0 && *(seq.end() - 1) > input[i])
			{
				continue;
			}           

			visited[input[i]] = true;

			seq.push_back(input[i]);

			DFS(seq.size());

			seq.pop_back();
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		input.push_back(temp);
	}

	sort(input.begin(), input.end());

	DFS(0);
}
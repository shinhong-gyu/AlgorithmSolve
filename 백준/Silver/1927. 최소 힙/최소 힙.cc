#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> heap;

	vector<int> output;

	while (N--)
	{
		int temp;
		cin >> temp;
		if (temp == 0)
		{
			if (heap.empty()) output.push_back(0);
			else
			{
				output.push_back(heap.top());
				heap.pop();
			}
		}
		else
		{
			heap.push(temp);
		}
	}
	for (auto n : output)
	{
		cout << n << "\n";
	}
}
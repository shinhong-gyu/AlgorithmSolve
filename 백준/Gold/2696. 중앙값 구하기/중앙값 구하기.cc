#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		int middle;

		priority_queue<int, vector<int>, less<int>> maxHeap;
		priority_queue<int, vector<int>, greater<int>> minHeap;

		int N;
		cin >> N;

		cout << (N / 2) + 1 << "\n";

		vector<int> nums;

		for (int i = 0; i < N; i++)
		{
			int num;
			cin >> num;
			nums.push_back(num);
		}

		int count = 0;
		for (int i = 1; i <= N; i++)
		{
			int num = nums[i - 1];

			if (i == 1)
			{
				maxHeap.push(num);
				middle = num;
				cout << middle << " ";
			}
			else
			{
				if (num < middle)
				{
					maxHeap.push(num);
				}
				else
				{
					minHeap.push(num);
				}

				if (i % 2 == 1)
				{
					if (maxHeap.size() > minHeap.size())
					{
						while (maxHeap.size() != minHeap.size() + 1)
						{
							int temp = maxHeap.top();
							maxHeap.pop();
							minHeap.push(temp);
						}
					}
					else
					{
						while (maxHeap.size() != minHeap.size() + 1)
						{
							int temp = minHeap.top();
							minHeap.pop();
							maxHeap.push(temp);
						}
					}

					middle = maxHeap.top();
					count++;
					if (count % 10 == 0)
					{
						cout << "\n";
					}
					cout << middle << " ";
				}
				else
				{
					if (maxHeap.size() > minHeap.size())
					{
						while (maxHeap.size() != minHeap.size())
						{
							int temp = maxHeap.top();
							maxHeap.pop();
							minHeap.push(temp);
						}
					}
					else
					{
						while (maxHeap.size() != minHeap.size())
						{
							int temp = minHeap.top();
							minHeap.pop();
							maxHeap.push(temp);
						}
					}
				}
			}
		}
		cout << '\n';
	}
}
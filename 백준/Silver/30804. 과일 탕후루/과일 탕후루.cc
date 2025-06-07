#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> fruits(N);

	bool onlyOne = true;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		fruits[i] = temp;

		if (i != 0 && fruits[i - 1] != temp)
		{
			onlyOne = false;
		}
	}

	if (onlyOne == true)
	{
		cout << fruits.size();
		return 0;
	}

	int front = 0;
	int idx = 0;

	int max = 0;

	unordered_map<int, int> m;

	for (int back = front; back < N; back++)
	{
		m[fruits[back]]++;

		while (m.size() > 2)
		{
			m[fruits[front]]--;

			if (m[fruits[front]] == 0)
			{
				m.erase(fruits[front]);
			}

			front++;
		}

		if (m.size() == 2)
		{
			if (max < back - front + 1)
			{
				max = back - front + 1;
			}
		}
	}


	cout << max;
}
#include <iostream>
#include <vector>
#include <climits>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N >> M;

	vector<int> V(N);

	int start = 0;
	int end = 0;
	int len = 100001;
	long long section = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> V[i];

	}


	while (end < N)
	{
		section += V[end];

		while (section >= M)
		{
			len = min(len, end - start + 1);
			section -= V[start];
			start++;
		}
		end++;
	}

	if (len == 100001)
	{
		cout << 0;
	}
	else
	{
		cout << len;
	}

}
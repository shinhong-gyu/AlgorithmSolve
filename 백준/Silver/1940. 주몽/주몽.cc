#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,M;
	cin >> N >> M;

	vector<int> resource(N,0);

	int start = 0;
	int end = N-1;
	int count = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> resource[i];
	}
	
	sort(resource.begin(), resource.end());

	while (start < end)
	{
		if (resource[start] + resource[end] == M)
		{
			count++;
			start++;
			end--;
		}
		else if (resource[start] +resource[end] < M)
		{
			start++;
		}
		else
		{
			end--;
		}
	}
	cout << count << "\n";
}
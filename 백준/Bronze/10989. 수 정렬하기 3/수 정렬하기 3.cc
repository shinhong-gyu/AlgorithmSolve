#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,count;
	cin >> N;

	int cnt[10001] = {0};

	for (int i = 0; i < N; i++)
	{
		cin >> count;
		cnt[count]++;
	}

	for (int i = 0; i < 10001; i++)
	{
		for (int j = 0; j < cnt[i]; j++)
		{
			cout << i << "\n";
		}
	}
}
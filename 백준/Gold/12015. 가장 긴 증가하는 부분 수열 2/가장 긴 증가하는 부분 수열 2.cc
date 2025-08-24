#include <iostream>
#include <vector>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> num(N);

	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}

	vector<int> lis(N);

	lis[0] = num[0];

	int length = 1;

	for (int i = 1; i < N; i++)
	{
		if (num[i] > lis[length - 1])
		{
			lis[length++] = num[i];
		}
		else
		{
			vector<int>::iterator iter = lower_bound(lis.begin(), lis.begin() + length, num[i]);

			*iter = num[i];

		}
	}

	cout << length;
}
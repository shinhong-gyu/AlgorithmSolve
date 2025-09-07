#include <iostream>
#include <vector>
#include <string>

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

	vector<int> lis;
	vector<int> pos(N);

	lis.push_back(num[0]);
	pos[0] = 0;

	for (int i = 1; i < N; i++)
	{
		if (num[i] > lis[lis.size() - 1])
		{
			pos[i] = lis.size();
			lis.push_back(num[i]);
		}
		else
		{
			vector<int>::iterator iter = lower_bound(lis.begin(), lis.end(), num[i]);

			pos[i] = iter - lis.begin();

			*iter = num[i];
		}
	}

	cout << lis.size() << endl;

	vector<int> rlis;

	int search = lis.size() - 1;
	for (int i = N - 1; i >= 0; i--)
	{
		if (pos[i] == search)
		{
			rlis.push_back(num[i]);
			search--;
		}
	}

	for (auto iter = rlis.rbegin(); iter < rlis.rend(); iter++)
	{
		cout << *iter << " ";
	}
}
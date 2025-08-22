#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int check[1000001] = { 0 };
bool numCheck[1000001] = { false };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> v(N);
	vector<int> score(N);

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		v[i] = temp;
		numCheck[temp] = true;
	}


	for (int i = 0; i < (int)v.size(); i++)
	{
		for (int j = v[i]; j <= 1000000; j += v[i])
		{
			check[j]++;

			if (numCheck[j])
			{
				score[i]++;
			}
		}
	}

	for (int i = 0; i < (int)v.size(); i++)
	{
		cout << score[i] - check[v[i]] << " ";
	}
}
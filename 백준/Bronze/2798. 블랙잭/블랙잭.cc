#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> cards(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> cards[i];
	}

	int sum = 0;

	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				int temp = cards[i] + cards[j] + cards[k];
				if (temp <= M && abs(M - temp) < abs(M - sum))
					sum = temp;
			}
		}
	}
	cout << sum << endl;

}
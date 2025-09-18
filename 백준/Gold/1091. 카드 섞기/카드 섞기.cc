#include <iostream>
#include <queue>
#include <string>
#include <numeric>
#include <cmath>
#include <vector>
#include <cctype>
#include <map>

using namespace std;

int N;
vector<int> P;
vector<int> origin;
vector<int> card;
vector<int> S;

int sCount = 0;

bool Check()
{
	for (int i = 0; i < N; i++)
	{
		if (P[card[i]] != i % 3)
		{
			return false;
		}
	}
	return true;
}


void Suffle()
{
	sCount++;
	vector<int> temp(N);

	for (int i = 0; i < N; i++)
	{
		temp[S[i]] = card[i];
	}

	card = temp;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	P.resize(N);
	S.resize(N);
	card.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> P[i];
	}


	for (int i = 0; i < N; i++)
	{
		cin >> S[i];
	}


	origin = card;

	iota(card.begin(), card.end(), 0);

	map<vector<int>, bool> visited;

	while (!Check())
	{
		if (visited[card])
		{
			cout << -1;
			return 0;
		}

		visited[card] = true;

		Suffle();


	}
	cout << sCount;

}
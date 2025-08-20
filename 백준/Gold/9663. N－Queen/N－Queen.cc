#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cases = 0;
int N;

vector<bool> colUse;
vector<bool> upDiagUse;
vector<bool> downDiagUse;

void NQueen(int row)
{
	if (row == N)
	{
		cases++;
		return;
	}

	for (int col = 0; col < N; col++)
	{
		if (!colUse[col] && !upDiagUse[row + col] && !downDiagUse[row - col + N - 1])
		{
			colUse[col] = true;
			upDiagUse[row + col] = true;
			downDiagUse[row - col + N - 1] = true;

			NQueen(row + 1);

			colUse[col] = false;
			upDiagUse[row + col] = false;
			downDiagUse[row - col + N - 1] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	colUse.resize(N,false);
	upDiagUse.resize(2 * N - 1,false);
	downDiagUse.resize(2 * N - 1,false);

	NQueen(0);

	cout << cases;
}
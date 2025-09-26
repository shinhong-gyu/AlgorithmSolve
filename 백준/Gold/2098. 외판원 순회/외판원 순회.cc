#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define INF 12345678

using namespace std;

// dp[c][v] 현재 도시가 c, 현재까지 방문한 모든 도시 리스트가 v일 때 앞으로 남은 모든 도시를 경유하는데 필요한 최소비용

int N;
int dp[16][1 << 16];
int W[16][16];



int tsp(int c, int v)
{
	// 모든 도시를 방문했을 때
	if (v == (1 << N) - 1)
	{
		return W[c][0] == 0 ? INF : W[c][0];
	}
	// 메모이제이션
	if (dp[c][v] != 0)
	{
		return dp[c][v];
	}

	int result = INF;

	for (int i = 0; i < N; i++)
	{
		if ((v & 1 << i) == 0 && W[c][i] != 0)
		{
			result = min(result, tsp(i, (v | 1 << i)) + W[c][i]);
		}
	}

	dp[c][v] = result;

	return result;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> W[i][j];
		}
	}

	cout << tsp(0, 1) << endl;
}
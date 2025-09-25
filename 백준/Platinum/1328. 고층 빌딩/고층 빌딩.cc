#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define mod 1000000007

using namespace std;



unsigned long long dp[101][101][101] = { 0 };

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L, R;
	cin >> N >> L >> R;

	// 가장 큰 건물을 세워놓고 시작
	dp[1][1][1] = 1;


	for (int n = 2; n <= N; n++)
	{
		for (int l = 1; l <= L; l++)
		{
			for (int r = 1; r <= R; r++)
			{
				// 기존에 있던 빌딩보다 작은 빌딩 중 가장 큰 빌딩을 배치하는 경우의 수
				// 제일 왼쪽에 놓는 경우, 제일 오른쪽에 놓는 경우, 중간 어딘가 아무 곳에나 놓는 경우
				dp[n][l][r] = dp[n - 1][l - 1][r] + dp[n - 1][l][r - 1] + dp[n - 1][l][r] * (n - 2);
				dp[n][l][r] %= mod;
			}
		}
	}

	cout << dp[N][L][R];
}
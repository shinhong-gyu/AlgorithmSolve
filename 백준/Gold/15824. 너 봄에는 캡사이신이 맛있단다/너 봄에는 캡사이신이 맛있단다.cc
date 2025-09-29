#include <iostream>
#include <vector>
#include <algorithm>

#define mod 1000000007

using namespace std;

vector<int> food;

unsigned long long myPow(int n)
{
	if (n == 0)
	{
		return 1;
	}

	unsigned long long temp = (myPow(n / 2));

	unsigned long long result = (temp * temp) % mod;

	if (n % 2 == 1)
	{
		result = (result * 2) % mod;
	}

	return result;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	if (N == 1)
	{
		cout << 0;
		return 0;
	}

	food.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> food[i];
	}

	sort(food.begin(), food.end());

	// 최대값을 K로하는 조합의 수 2^N-1 
	// A = 최대 - 최소 의 총합, B = 조합의 개수 / (A * B) % mod = ( A % mod * B % mod ) % mod
	unsigned long long answer = 0;

	// A = (조합의 최대값들의 총합) - (조합의 최소값들의 총합)
	// (조합의 최대값들의 총합) = 요소 * 요소별로 최대값이 되는 조합의 수
	// (조합의 최소값들의 총합) = 요소 * 요소별로 최소값이 되는 조합의 수

	// i를 최대로하는 조합의 수
	// 제일 작은 수를 최대로하는 조합은 없음

	for (int i = 0; i < N; i++)
	{
		unsigned long long max_count = myPow(i);

		unsigned long long min_count = myPow(N - 1 - i);

		long long factor = (max_count - min_count + mod) % mod;

		unsigned long long term = ((unsigned long long)food[i] * factor) % mod;

		answer = (answer + term) % mod;
	}

	cout << answer;
}
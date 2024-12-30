#include <iostream>
#include <queue>

using namespace std;

int main()
{
	// 입력 N -> 맨 아래 깔릴 숫자 카드 => 	큐에 제일 먼저 들어갈 숫자
	int N;
	cin >> N;

	queue<int> q;

	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}

	while (q.size() > 1)
	{
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front();
}
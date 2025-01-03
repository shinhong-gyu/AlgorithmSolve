#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	unordered_map<int, int> m;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		m[temp]++;
	}

	int M;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;

		cout << m[temp] << " ";
	}
}
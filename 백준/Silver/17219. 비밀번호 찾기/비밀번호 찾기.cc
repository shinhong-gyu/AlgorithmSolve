#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	unordered_map<string, string> storage;

	for (int i = 0; i < N; i++)
	{
		string temp1, temp2;
		cin >> temp1 >> temp2;

		storage[temp1] = temp2;
	}

	for (int i = 0; i < M; i++)
	{
		string  temp;
		cin >> temp;

		cout << storage[temp] << "\n";
	}
}
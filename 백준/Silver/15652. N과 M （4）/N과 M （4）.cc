#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N >> M;

	queue<string>  q;


	q.push(string());

	while (!q.empty())
	{
		string cur = q.front();

		q.pop();

		if (cur.length() == M)
		{
			for (char c : cur)
			{
				cout << c << " ";
			}
			cout << "\n";

			continue;
		}

		for (int i = 1; i <= N; i++)
		{
			string temp = cur;

			if (temp.length() < M)
			{
				if (temp.empty() || (temp.back() - '0' <= i)) 
				{
					temp += to_string(i);
					q.push(temp);
				}
			}
		}
	}
}
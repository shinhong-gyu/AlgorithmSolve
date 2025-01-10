#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;


	while (T--)
	{
		int N;
		cin >> N;

		unordered_map<string, int> category;
		for (int i = 0; i < N; i++)
		{
			string temp1, temp2;
			cin >> temp1 >> temp2;

			category[temp2]++;
		}
		int result = 1;
		// 하나의 카테고리에서 하나씩 뽑거나 뽑지 않는 경우의 수. 최소한 모든 카테고리중에서 한개는 뽑아야함
		for (auto p : category)
		{
			result *= (p.second + 1);
		}
		cout << result - 1 << endl;
	}

}
#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	unordered_map<int, string> dic;
	unordered_map<string, int> rev_dic;

	for (int i = 1; i <= N; i++)
	{
		string temp;
		cin >> temp;
		dic[i] = temp;
		rev_dic[temp] = i;
	}

	for (int i = 0; i < M; i++)
	{
		string temp;
		cin >> temp;

		if (isdigit(temp[0]))
		{
			cout << dic[stoi(temp)] << "\n";
		}
		else
		{
			cout << rev_dic[temp] << "\n";
		}
	}

}
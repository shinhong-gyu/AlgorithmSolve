#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <unordered_set>


using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N, M;
	cin >> N >> M;

	vector<string> answer;
	unordered_set<string> v;

	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		v.insert(temp);
	}

	for (int i = 0; i < M; i++)
	{
		string temp;
		cin >> temp;
		if(v.count(temp)) answer.push_back(temp);
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << "\n";

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}
}
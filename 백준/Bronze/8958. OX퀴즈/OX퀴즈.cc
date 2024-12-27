#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	string answerList = " ";
	int score = 0;
	int combo = 0;
	for (int i = 0; i < T; i++)
	{
		score = 0;
		combo = 0;
		cin >> answerList;
		for (auto answer : answerList)
		{
			if (answer == 'O') {
				combo++;
				score += combo;
			}
			else
			{
				combo = 0;
			}
		}
		cout << score << "\n";
	}
}
#include  <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int line = 0;
	int leastInLine = 1;
	int greatesInLine = 1;

	while (N > greatesInLine)
	{
		leastInLine = greatesInLine + 1;
		greatesInLine = greatesInLine + line * 6;
		line++;
	}
	if (N == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	cout << line << endl;
}
#include <iostream>
#include <string>

using namespace std;


string str;

bool IsPalindrom(int s, int e)
{
	if (e - s <= 0)
	{
		return true;
	}

	if (str[s] == str[e])
	{
		return IsPalindrom(s + 1, e - 1);
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> str;

	cout << IsPalindrom(0, str.length() - 1);

}
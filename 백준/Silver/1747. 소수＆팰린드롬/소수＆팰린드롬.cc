#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool IsPalindrom(const string& str)
{
	if (str.size() == 1 || str.size() == 0)
	{
		return true;
	}

	if (str[0] == str[str.size() - 1])
	{
		return IsPalindrom(str.substr(1, str.length() - 2));
	}
	else
	{
		return false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<bool> isPrime(1100001, true);

	isPrime[0] = false;
	isPrime[1] = false;

	for(int i = 2; i <= 1100000; i++)
	{
		if (isPrime[i] == true)
		{
			for (int j = i + i; j <= 1100000; j += i)
			{
				isPrime[j] = false;
			}
		}
	}

	for (int i = N; i <= 1100000; i++)
	{
		if (IsPalindrom(to_string(i)) && isPrime[i])
		{
			cout << i;
			return 0;
		}
	}
}
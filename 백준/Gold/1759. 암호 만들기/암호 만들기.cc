#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> alpha;
vector<char> code;

int vowel = 0;
int consonant = 0;

int L, C;

void solve(int n)
{
	if (code.size() == L && vowel >= 1 && consonant >= 2)
	{
		for (int i = 0; i < (int)code.size(); i++)
		{
			cout << code[i];
		}
		cout << "\n";

		return;
	}

	for (int i = n; i < C; i++)
	{
		code.push_back(alpha[i]);

		if (alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'o' || alpha[i] == 'i' || alpha[i] == 'u')
		{
			vowel++;
		}
		else
		{
			consonant++;
		}

		solve(i + 1);

		if (alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'o' || alpha[i] == 'i' || alpha[i] == 'u')
		{
			vowel--;
		}
		else
		{
			consonant--;
		}

		code.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> L >> C;

	alpha.resize(C);

	for (int i = 0; i < C; i++)
	{
		cin >> alpha[i];
	}

	sort(alpha.begin(), alpha.end());

	solve(0);
}
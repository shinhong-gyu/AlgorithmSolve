#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
	int N, K;

	list<int> numList;
	list<int>::iterator current = numList.end();

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		numList.push_back(i);
		if (numList.size() == 1)
			current = numList.begin();
	}

	cout << "<";
	while (numList.size() > 0)
	{
		for (int i = 0; i < K - 1; i++)
		{
			if (!numList.empty())
			{
				current++;
				if (current == numList.end())
				{
					current = numList.begin();
				}
			}
		}
		auto toErase = current;
		if (numList.size() == 1)
		{
			cout << *current;
		}
		else cout << *current << ", ";
		if (numList.size() == 1)
		{
			numList.erase(toErase);
			current = numList.end();
		}
		else
		{
			current++;
			if (current == numList.end())
			{
				current = numList.begin();
			}
			numList.erase(toErase);
		}
	}
	cout << ">";
}
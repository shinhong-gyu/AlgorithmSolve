#include <iostream>
#include <vector>

using namespace std;

int N, M;

void makeSequence(vector<int> sequence, int num)
{
	sequence.push_back(num);

	if (sequence.size() == M)
	{
		for (int n : sequence)
		{
			cout << n << " ";
		}
		cout << "\n";
	}

	for (int i = 1; i <= N; i++)
	{
		if (i > num)
		{
			makeSequence(sequence, i);
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		vector<int> sequence;
		makeSequence(sequence, i);
	}
}
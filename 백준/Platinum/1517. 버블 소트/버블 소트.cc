#include <vector>
#include <iostream>

using namespace std;

vector<int> v;
vector<int> temp;

long answer = 0;

void mergeSort(int s, int e)
{
	if (e - s < 1)
	{
		return;
	}

	int mid = s + (e - s) / 2;

	mergeSort(s, mid);
	mergeSort(mid + 1, e);

	for (int i = s; i <= e; i++)
	{
		temp[i] = v[i];
	}

	int k = s;
	int idx1 = s;
	int idx2 = mid + 1;

	while (idx1 <= mid && idx2 <= e)
	{
		if (temp[idx1] <= temp[idx2])
		{
			v[k] = temp[idx1];

			k++;
			idx1++;
		}
		else
		{
			v[k] = temp[idx2];

			answer = answer + idx2 - k;

			k++;
			idx2++;
		}
	}

	while (idx1 <= mid)
	{
		v[k] = temp[idx1];

		k++;
		idx1++;
	}

	while (idx2 <= e)
	{
		v[k] = temp[idx2];

		k++;
		idx2++;
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	v.resize(N + 1, 0);
	temp.resize(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		cin >> v[i];
	}

	answer = 0;
	mergeSort(1, N);

	cout << answer<<"\n";
	return 0;
}
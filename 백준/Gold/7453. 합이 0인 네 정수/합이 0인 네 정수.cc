#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;
#define ll long long

ll A[4000];
ll B[4000];
ll C[4000];
ll D[4000];



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}


	vector<ll> vCD;
	vector<ll> vAB;


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			vAB.push_back(A[i] + B[j]);

			vCD.push_back(C[i] + D[j]);
		}
	}

	sort(vAB.begin(), vAB.end());
	sort(vCD.begin(), vCD.end());

	ll count = 0;
	int left = 0;
	int right = vCD.size() - 1;

	while (left < vAB.size() && right >= 0)
	{
		ll sum = vAB[left] + vCD[right];

		ll abCount = 0;
		ll cdCount = 0;

		if (sum == 0)
		{
			ll abCur = vAB[left];
			ll cdCur = vCD[right];

			while (left < vAB.size() &&vAB[left] == abCur )
			{
				abCount++;
				left++;
			}
			while (right >= 0&& vCD[right] == cdCur )
			{
				cdCount++;
				right--;
			}

			count += (abCount * cdCount);
		}
		else if (sum < 0)
		{
			left++;
		}
		else
		{
			right--;
		}
	}

	cout << count;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> num(N);

	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}

	// dp[i] : 0~i까지 i를 포함하는 가장 길게 증가하는 수열의 길이
	vector<int> dp(N);
	vector<int> seq;

	dp[0] = 1;
	seq.push_back(num[0]);

	for (int i = 1; i < N; i++)
	{
		int cur = num[i];

		if (cur > seq.back())
		{
			seq.push_back(cur);
			dp[i] = seq.size();
		}
		else
		{
			// seq에서 cur보다 같거나 큰 수 중 제일 작은 값 찾기
			int s = 0;
			int e = seq.size() - 1;

			int idx = i;

			while (s <= e)
			{
				int mid = (s + e) / 2;

				if (seq[mid] > cur)
				{
					idx = mid;
					e = mid - 1;
				}
				else if (seq[mid] < cur)
				{
					s = mid + 1;
				}
				else
				{
					idx = mid;

					while (idx != 0 && seq[idx - 1] == cur)
					{
						idx--;
					}

					break;
				}
			}

			seq[idx] = cur;
			dp[i] = idx + 1;
		}
	}

	int len = *max_element(dp.begin(), dp.end());

	cout << len << "\n";

	vector<int> lis;

	for (int i = N - 1; i >= 0; i--)
	{
		if (dp[i] == len)
		{
			lis.push_back(num[i]);
			len--;
		}
	}

	for (auto iter = lis.rbegin(); iter < lis.rend(); iter++)
	{
		cout << *iter << " ";
	}
}
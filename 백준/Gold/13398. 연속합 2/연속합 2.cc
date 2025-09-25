
// #include <iostream>
// #include <vector>
// #include <algorithm>
// 
// using namespace std;
// 
// int main()
// {
// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);
// 
// 	int N;
// 	cin >> N;
// 
// 	vector<int> v(N);
// 	vector<int> negIdx;
// 
// 	for (int i = 0; i < N; i++)
// 	{
// 		cin >> v[i];
// 
// 		if (v[i] < 0)
// 		{
// 			negIdx.push_back(i);
// 		}
// 
// 	}
// 
// 	// i번째까지의 최대 연속 합과 제거한 수의 인덱스
// 	vector<int> dp(N);
// 	vector<int> left_dp(N);
// 
// 	dp[0] = v[0];
// 	left_dp[0] = v[0];
// 
// 	for (int i = 1; i < N; i++)
// 	{
// 		dp[i] = max(dp[i - 1] + v[i], v[i]);
// 		left_dp[i] = max(left_dp[i - 1] + v[i], v[i]);
// 	}
// 
// 	vector<int> right_dp(N);
// 
// 	right_dp[N - 1] = v[N - 1];
// 
// 
// 	for (int i = N - 2; i >= 0; i--)
// 	{
// 		right_dp[i] = max(right_dp[i + 1] + v[i], v[i]);
// 	}
// 
// 	for (int i : negIdx)
// 	{
// 		if (i > 0 && i < N - 1)
// 		{
// 			dp[i] = max(dp[i],right_dp[i + 1] + left_dp[i - 1]);
// 		}
// 	}
// 
// 
// 
// 	cout << *max_element(dp.begin(), dp.end());
// }
// 
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int N;
//	cin >> N;
//
//	vector<int> v(N);
//	vector<int> S(N);
//
//	for (int i = 0; i < N; i++)
//	{
//		cin >> v[i];
//
//		if (i != 0)
//		{
//			S[i] = S[i - 1] + v[i];
//
//		}
//		else
//		{
//			S[i] = v[i];
//		}
//	}
//
//	// i번째까지의 최대 연속 합과 제거한 수의 인덱스
//	vector<int> dp(N);
//	// 음수를 만날 때마다 해당 음수를 제거한 연속 합을 계산 그리고 기존 최대값과 비교
//
//	int removed = -1;
//	int lastNeg = -1;
//	dp[0] = v[0];
//
//	for (int i = 1; i < N; i++)
//	{
//		if (v[i] < 0)
//		{
//			lastNeg = i;
//
//			if (removed != -1)
//			{
//				int temp = S[i] - S[removed] - v[i];
//
//				dp[i] = max(dp[i - 1], temp);
//
//				removed = dp[i] > temp ? removed : i;
//			}
//			else
//			{
//				removed = i;
//
//				dp[i] = S[i] - v[i];
//			}
//		}
//		else
//		{
//			// 마지막으로 나온 음수를 제거한 연속 부분합
//			int temp = -1001;
//
//			if (removed != -1 && removed != lastNeg)
//			{
//				temp = S[i] - v[lastNeg];
//
//				// lastNeg를 제거한 연속 부분합이 dp[i-1]에 v[i](현재 값)를 더한 것보다 크다면 lastNeg를 removed로 갱신
//				removed = dp[i - 1] > temp ? removed : lastNeg;
//
//				dp[i] = max(dp[i - 1], temp);
//			}
//			else
//			{
//				dp[i] = max(dp[i - 1] + v[i], v[i]);
//			}
//		}
//	}
//
//	cout << *max_element(dp.begin(), dp.end());
//}
//

#include <vector>
#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> num(N);
	vector<int> negIdx;

	for (int i = 0; i < N; i++)
	{
		cin >> num[i];

		if (num[i] < 0)
		{
			negIdx.push_back(i);
		}
	}

	vector<int> L(N);
	vector<int> R(N);

	L[0] = num[0];
	R[0] = num[N - 1];
	int maxValue = max(L[0], R[0]);

	for (int i = 1; i < N; i++)
	{
		L[i] = max(num[i], L[i - 1] + num[i]);
		R[i] = max(num[N - i - 1], R[i - 1] + num[N - i - 1]);

		maxValue = max(maxValue,max(L[i], R[i]));
	}

	for (int idx : negIdx)
	{
		if (idx > 0 && idx < N - 1)
		{
			maxValue = max(maxValue, L[idx - 1] + R[N - 1 - idx -1]);
		}
	}

	cout << maxValue;
}
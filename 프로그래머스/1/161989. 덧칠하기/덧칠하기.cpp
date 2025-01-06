#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, int m, vector<int> section) {
	vector<bool> painted(n, true);
	int answer = 0;

	for (auto s : section)
	{
		painted[s - 1] = false;
	}

	int min = *min_element(section.begin(), section.end()) - 1;
	int max = *max_element(section.begin(), section.end()) - 1;


	int i = min;
	while (i<=max)
	{
		if (!painted[i])
		{

			answer++;
			for (int j = i; j < i + m && j <= max; j++)
			{
				painted[j] = true;
			}
		}
		i++;
	}
    
    return answer;
}
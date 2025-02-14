#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
	return a + b > b + a;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> nums;

	for (int i = 0; i < numbers.size(); i++)
	{
		nums.push_back(to_string(numbers[i]));
	}

	sort(nums.begin(),nums.end(),compare);

    if(nums[0] == "0") return "0";
	for (auto num: nums)
	{
		answer+= num;
	}

	return answer;
}
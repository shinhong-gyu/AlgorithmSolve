#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    int max = nums.size()/2;
    set<int> s(nums.begin(),nums.end());
    
    return s.size() >= max ? max :s.size() ;
}
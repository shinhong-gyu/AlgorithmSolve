#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(),lost.end());
    sort(reserve.begin(),reserve.end());
    vector<int> lost2;
    
    for(auto n : lost)
    {
        if(find(reserve.begin(),reserve.end(),n) != reserve.end())
        {
            reserve.erase(find(reserve.begin(),reserve.end(),n));
        }
        else
        {
            lost2.push_back(n);
        }
    }
    
    int answer = n - lost2.size();

    for(auto n : lost2)
    {
        if(find(reserve.begin(),reserve.end(),n-1) != reserve.end())
        {
            answer++;
            reserve.erase(find(reserve.begin(),reserve.end(),n-1));
        }
        else if(find(reserve.begin(),reserve.end(),n+1)!= reserve.end())
        {
            answer++;
            reserve.erase(find(reserve.begin(),reserve.end(),n+1));
        }
        
    }
    return answer;
}
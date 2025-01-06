#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int count = 0;
    int min;
    vector<int> box;
    
    sort(score.begin(),score.end(),std::greater<int>());
    
    for(auto n : score)
    {
        count++;
        box.push_back(n);
        if(count==m)
        {
            min = box[m-1];
            count = 0;
            answer += (min*m);
            box.clear();
        }
    }
    
    return answer;
}
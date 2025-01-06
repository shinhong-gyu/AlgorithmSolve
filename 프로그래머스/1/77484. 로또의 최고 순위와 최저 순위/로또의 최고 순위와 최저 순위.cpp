#include <string>
#include <vector>
#include <iostream>

using namespace std;

int lottoRank(int correct)
{
    switch(correct)
    {
        case 2: return 5;
        case 3: return 4;
        case 4: return 3;
        case 5: return 2;
        case 6: return 1;
        default: return 6;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int count_right =0;
    int count_zero =0;
    for(int i = 0 ; i < 6 ; i++)
    {
        for(int j = 0; j<6;j++)
        {
            if(lottos[i] == win_nums[j])
            {
                count_right++;
                break;
            }
        }
        if(lottos[i] == 0) count_zero++;
    }
    answer.push_back(lottoRank(count_right+count_zero));
    answer.push_back(lottoRank(count_right));
    
    return answer;
}
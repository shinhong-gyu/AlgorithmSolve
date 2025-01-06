#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int pick3(int a, int b, int c,vector<int> p_num)
{
    return p_num[a] + p_num[b] + p_num[c];
}

int solution(vector<int> nums) {
    int answer = 0;
    int except,sum =0;
    bool check = false;
    for(int i = 0; i < nums.size(); i++)
    {
        for(int j = i+1; j<nums.size(); j++)
        {
            for(int k = j+1; k < nums.size(); k++)
            {
                sum = pick3(i,j,k,nums);
                for(int l = 2; l <= sqrt(sum); l++)
                {
                    if(sum%l == 0)
                    {
                        check = true;
                        break;
                    }
                }
                if(check != true && sum != 0) 
                {  
                    answer++;
                }
                check = false;
                sum = 0;
            } 
            
          
        }
    }
    
    return answer;
}
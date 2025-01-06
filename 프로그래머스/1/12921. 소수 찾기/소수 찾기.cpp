#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> check(n,true);
    for(int i = 2; i <= n; i++)
    {
        if(check[i])
        {
            for(int j = i*2; j <= n; j+=i)
            {
                check[j] = false;
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(check[i] == true) 
        {
            answer++;
        }
    }
    return answer-1;
}
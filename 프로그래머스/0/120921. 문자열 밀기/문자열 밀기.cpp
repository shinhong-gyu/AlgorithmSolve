#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string A, string B) {
    int answer = 0;
    char c_temp;
    string s_pre = A;
    string s_temp = "";
    if(A == B) return 0;
    
    for(int i = 0; i < A.length(); i++)
    {
        
        s_temp += s_pre[s_pre.length()-1];
        
        for(int j  = 0; j<A.length()-1; j++)
        {
            s_temp += s_pre[j];
        }
        s_pre = s_temp;
    
        if(s_temp == B)
        {
            return i+1;
        }
         s_temp = "";
    }
    return -1;
}
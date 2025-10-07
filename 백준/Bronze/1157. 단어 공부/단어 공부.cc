#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str;
    cin >> str;
    
    unordered_map<char,int> m;
    
    for(char c : str)
    {
        
        m[toupper(c)]++;
    }
    
    int temp = -1;
    char answer;
    
    for(auto p : m)
    {
        if(p.second > temp)
        {
            answer = p.first;
            temp = p.second;
        }
    }
    
    for(auto p : m)
    {
        if(answer != p.first && temp == p.second)
        {
            cout << "?";
            return 0;
        }
    }
    
    cout << answer;
}
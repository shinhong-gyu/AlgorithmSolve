#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string myString, string pat) {
    string l_myString;
    string l_pat;
    
    for(auto c : myString)
    {
        l_myString += tolower(c);
    }
    for(auto c : pat)
    {
        l_pat += tolower(c);
    }
    
    if(l_myString.find(l_pat)!=string::npos)
    {
        return 1;        
    }
    else
    {
        return 0;
    }
}
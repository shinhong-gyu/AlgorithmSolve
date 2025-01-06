#include <string>
#include <vector>
#include <algorithm>
#include <sstream>


using namespace std;

string solution(string s) {
    string answer = "";
    
    stringstream ss(s);
    
    string word;
    
    vector<string> v;
    
    while(ss>>word)
    {
        v.push_back(word);
    }
    
    vector<int> a;
    
    for(auto str : v)
    {
        a.push_back(stoi(str));
    }
    
    sort(a.begin(),a.end());
    
    string s1 = to_string(a[0]) + " " +to_string(a[a.size()-1]);
    return s1;
}
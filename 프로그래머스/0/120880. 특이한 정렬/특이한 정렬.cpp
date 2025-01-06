#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int mark;

bool compare(int a, int b)
{    
    if(abs(mark-a)<abs(mark-b))
        return true;
    else if(abs(mark-a)==abs(mark-b))
    {
        return a<b?false:true;
    }
    else return false;  
}

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    mark = n;
    sort(numlist.begin(),numlist.end(), compare);
    return numlist;
}
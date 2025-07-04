#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    
    int count = 0;
    for(auto c : str)
    {
        if(c == '@' || c == 'a' || c == 'A' || c =='b' || c =='d' || c == 'D' || c == 'e' || c == 'g' || c == 'O' || c == 'o' || c =='p' || c == 'P' || c== 'q' || c == 'Q' || c=='R')
        {
            count++;
        }
        
        else if(c == 'B')
        {
            count+=2;
        }
    }
    
    cout << count;
    
}
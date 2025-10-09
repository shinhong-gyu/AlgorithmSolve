#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    
    string str2;
    cin >> str2;
    
    if(str.length() < str2.length())
    {
        cout << "no";
    }
    else
    {
        cout << "go";
    }
}
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(1)
    {
    int A,B;
        cin >> A >> B;
        if(A == 0 && B == 0)
        {
            break;
        }
        
        if(A > B)
        {
             cout << "Yes\n";   
        }
        else
        {
            cout << "No\n";
        }
    }
}
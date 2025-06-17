#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,M;
    cin >> N >> M;
    
    vector<vector<int>> v(N,vector<int>(M));
    
    for(int i = 0 ; i< N; i++)
    {
        for(int j = 0 ; j< M; j++)
        {
            cin >> v[i][j];
        }
    }
    
    
    for(int i = 0 ; i< N; i++)
    {
        for(int j = 0 ; j< M; j++)
        {
            int temp;
            cin >> temp;
            cout << temp + v[i][j] << " ";
        }
        cout << endl;
    }
    
}
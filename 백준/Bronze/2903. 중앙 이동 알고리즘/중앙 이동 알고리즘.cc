#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int byun = 2;
    for(int i = 0; i<N;i++)
    {
       byun += (byun - 1);
    }
    cout << byun*byun;
}
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
    int T;
    int start_x, start_y, arrival_x, arrival_y, n;
    cin >> T;
    while (T) {
        int enter = 0, leave = 0;
        cin >> start_x >> start_y >> arrival_x >> arrival_y;

        cin >> n;
        int planet[50][3] = { 0 };
        double distance_s, distance_a;
        for (int i = 0; i < n; i++) {
            cin >> planet[i][0] >> planet[i][1] >> planet[i][2];

            distance_s = sqrt(pow((planet[i][0]-start_x),2)+pow((planet[i][1] - start_y),2));
            distance_a = sqrt(pow((planet[i][0] - arrival_x), 2) + pow((planet[i][1] - arrival_y), 2));
            //printf("%lf %lf\n", distance_s, distance_a);
            if (distance_s <= planet[i][2]) {
                if (distance_a > planet[i][2]) {
                    //cout << "진입" << endl;
                    leave++;
                }
            }
            if (distance_a <= planet[i][2]) {
                if (distance_s > planet[i][2]) {
                    //cout << "탈출" << endl;
                    enter++;
                }
            }
        }
        cout << enter + leave << endl;
        T--;
    }

}
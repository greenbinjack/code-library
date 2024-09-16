#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    double r1, r2, rad, h, p, pi = 2 * acos(0.0);
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> r1 >> r2 >> h >> p;
        rad = p / (h * 1.0) * (r1 - r2) + r2;
        cout << "Case " << i << ": ";
        cout << fixed << setprecision(9) << pi * (p / 3.0) * (rad * rad + r2 * r2 + (rad * r2)) << endl;
    }
    return 0;
}


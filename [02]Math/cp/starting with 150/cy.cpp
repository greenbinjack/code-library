#include<bits/stdc++.h>
using namespace std;

double calc_dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    int tc, n;
    double ox, oy, ax, ay, bx, by, oa, ob, ab;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> ox >> oy >> ax >> ay >> bx >> by;
        oa = calc_dist(ox, oy, ax, ay);
        ob = calc_dist(ox, oy, bx, by);
        ab = calc_dist(bx, by, ax, ay);
        cout << fixed << setprecision(9);
        cout << "Case " << testCase << ": " << oa * acos((oa*oa + ob*ob - ab*ab) / (2 * oa * ob)) << endl;
    }
    return 0;
}

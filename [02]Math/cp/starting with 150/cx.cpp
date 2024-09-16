#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, n;
    double bigRadius, smallRadius, pi = 2 * acos(0.0);
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> bigRadius >> n;
        smallRadius = (bigRadius * sin(pi / n * 1.0)) / (1.0 + sin(pi / n * 1.0));
        cout << fixed << setprecision(10);
        cout << "Case " << i << ": " << smallRadius << endl;
    }
    return 0;
}

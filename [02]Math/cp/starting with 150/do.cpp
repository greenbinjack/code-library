#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    double v1, v2, v3, a1, a2, t1, t2, bird, train;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> v1 >> v2 >> v3 >> a1 >> a2;
        t1 = v1 / a1;
        t2 = v2 / a2;
        bird = max(t1, t2) * v3;
        train = v1 * t1 - 0.5 * a1 * t1 * t1 + v2 * t2 - 0.5 * a2 * t2 * t2;
        cout << "Case " << i << ": " << fixed << setprecision(9) << train << ' ' << bird << endl;
    }
    return 0;
}


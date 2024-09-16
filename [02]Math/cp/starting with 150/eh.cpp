#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    double a, b, r, angle, x;
    char temp;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> a >> temp >> b;
        r = sqrt(a * a + b * b) / 2.0;
        angle = acos((2 * r * r - b * b) / (2 * r * r));
        x = 200.0 / (a + r * angle);
        a *= x;
        b *= x;
        cout << fixed << setprecision(9) << "Case " << i << ": " << a << ' ' << b << endl;
    }
    return 0;
}

/*
sample cases:

10
10 2 8 1 2 4 1 20 4 5


*/



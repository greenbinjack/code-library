#include<bits/stdc++.h>
using namespace std;

int lanterns(int x, int y) { return x / y; }

int main()
{
    int tc, L, v, l, r;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> L >> v >> l >> r;
        cout << (L / v) - (r / v) + ((l - 1) / v) << endl;
    }
    return 0;
}




#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, r, g, b, mx, mn, middle;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> r >> g >> b;
        mx = max({r, g, b});
        mn = min({r, g, b});
        middle = r + g + b - mx - mn;
        if(mx <= mn + middle) cout << (r + g + b) / 2 << endl;
        else cout << mn + middle << endl;
    }
    return 0;
}

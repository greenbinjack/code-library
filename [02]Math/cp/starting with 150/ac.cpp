#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, a, b, c, r, left, right;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> a >> b >> c >> r;
        if(a > b) swap(a, b);
        left = max(a, c - r), right = min(b, c + r);
        cout << b - a - max(0, right - left) << endl;
    }
    return 0;
}


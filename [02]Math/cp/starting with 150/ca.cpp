#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, timeLimit, mn = INT_MAX, c, t;
    cin >> n >> timeLimit;
    for(int i=1;i<=n;i++) {
        cin >> c >> t;
        if(t <= timeLimit && c < mn) mn = c;
    }
    if(mn == INT_MAX) cout << "TLE" << endl;
    else cout << mn << endl;

    return 0;
}


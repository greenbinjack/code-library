#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, x, y;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> x >> y;
        if(x - y == 1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}


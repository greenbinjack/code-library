#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, n, sum, s;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> n;
        sum = 0;
        for(int j=1;j<=n;j++) {
            cin >> s;
            if(s <= 2048) sum += s;
        }
        if(sum >= 2048) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}



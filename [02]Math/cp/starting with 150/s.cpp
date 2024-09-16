#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, n, m, p[2], q[2], temp;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        p[0] = p[1] = q[0] = q[1] = 0;
        cin >> n;
        for(int j=1;j<=n;j++) {
            cin >> temp;
            p[temp % 2]++;
        }
        cin >> m;
        for(int j=1;j<=m;j++) {
            cin >> temp;
            q[temp % 2]++;
        }
        cout << p[0] * q[0] + p[1] * q[1] << endl;
    }
    return 0;
}


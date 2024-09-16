#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, r1, c1, r2, c2;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> r1 >> c1 >> r2 >> c2;
        if((r1 + c1) % 2 != (r2 + c2) % 2) cout << "Case " << i << ": " << "impossible" << endl;
        else if(abs(r1 - r2) == abs(c1 - c2)) cout << "Case " << i << ": " << 1 << endl;
        else cout << "Case " << i << ": " << 2 << endl;
    }
    return 0;
}

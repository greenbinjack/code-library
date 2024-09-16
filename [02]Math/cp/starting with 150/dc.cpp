#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, pos1, pos2;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> pos1 >> pos2;
        cout << "Case " << i << ": ";
        if(pos1 <= pos2) cout << 10 + 4 * pos2 + 9 << endl;
        else cout << 10 + 4 * (2 * pos1 - pos2) + 9 << endl;
    }
    return 0;
}


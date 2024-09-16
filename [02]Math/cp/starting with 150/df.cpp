#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, n, x1, y1, x2, y2, x, y;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> n;
        cout << "Case " << i << ": " << endl;
        for(int j=1;j<=n;j++) {
            cin >> x >> y;
            if(x > x1 && x < x2 && y > y1 && y < y2) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}

/*
sample cases:

10
10 2 8 1 2 4 1 20 4 5


*/


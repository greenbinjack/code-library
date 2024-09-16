#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    long long w, n, m, base;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> w;
        if(w % 2 == 0) {
            base = 1;
            for(int j=1;j<63;j++) {
                base *= 2;
                if(w % base  == 0) {
                    m = base;
                    n =  w / m;
                }
            }
            cout << "Case " << i << ": " << n << ' ' << m << endl;
        }
        else cout << "Case " << i << ": " << "Impossible" << endl;
    }
    return 0;
}





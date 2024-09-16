#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, pos, ans[25];
    long long n, fact[25];
    fact[0] = 1;
    for(long long i=1;i<=19;i++) fact[i] = fact[i - 1] * i;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> n;
        pos = 0;
        for(int j=19;j>=0;j--) {
            if(n >= fact[j]) {
                n -= fact[j];
                ans[pos] = j;
                pos++;
            }
        }
        cout << n << endl;
        if(n == 0) {
            cout << "Case " << i << ": ";
            for(int j=pos-1;j>0;j--) cout << ans[j] << "!+";
            cout << ans[0] << "!" << endl;
        }
        else cout << "Case " << i << ": " << "impossible" << endl;
    }
    return 0;
}

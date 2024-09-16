#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, n, temp, rev, rem;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> n;
        temp = n, rev = 0;
        while(temp) {
            rem = temp % 10;
            rev = rev * 10 + rem;
            temp /= 10;
        }
        if(n == rev) cout << "Case " << i << ": " << "Yes" << endl;
        else cout << "Case " << i << ": " << "No" << endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, n;
    string s;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> n >> s;
        if(n > 2 || s[1] > s[0]) {
            cout << "YES" << endl;
            cout << 2 << endl;
            cout << s[0] << ' ' << s.substr(1, n-1) << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, sz;
    string s;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> s;
        sz = s.size();
        if(sz > 10) cout << s[0] << sz - 2 << s[sz - 1] << endl;
        else cout << s << endl;
    }
    return 0;
}


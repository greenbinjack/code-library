#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, n, rem;
    string s;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> s >> n;
        rem = 0;
        for(int j=0;j<s.size();j++) {
            if(s[j] == '-') continue;
            rem = rem * 10 + (s[j] - '0');
            rem %= n;
        }
        if(rem > 0) cout << "Case " << i << ": " << "not divisible" << endl;
        else cout << "Case " << i << ": " << "divisible" << endl;
    }
    return 0;
}


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int sz, flag = 0;
    string s, t;
    cin >> s >> t;
    s += s;
    sz = t.size();
    for(int i=0;i<sz;i++) {
        if(s.substr(i, sz) == t) {
            flag = 1;
            break;
        }
    }
    if(flag == 1) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}



#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s, fi, se;
    cin >> n >> s;
    if(n%2 == 1) cout << "No" << endl;
    else {
        fi = s.substr(0, n/2);
        se = s.substr(n/2, n/2);
        if(fi == se) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}

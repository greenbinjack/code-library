#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int n, isBerlanese = 1;
    cin >> s;
    n = s.size();
    for(int i=0;i<n;i++) {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'n') continue;
        else {
            if(i + 1 == n) isBerlanese = 0;
            else if(s[i + 1] != 'a' && s[i + 1] != 'e' && s[i + 1] != 'i' && s[i + 1] != 'o' && s[i + 1] != 'u') isBerlanese = 0;
        }
    }
    if(isBerlanese == 1) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}


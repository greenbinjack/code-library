#include<bits/stdc++.h>
using namespace std;

int main()
{
    char s[205], ans[205];
    int id = 0;
    cin >> s;
    for(int i=0;i<=strlen(s);i++) {
        if(s[i]=='W' && s[i+1]=='U' && s[i+2]=='B') i+=2;
        else{
            ans[id] = s[i];
            id++;
            if(s[i+1]=='W' && s[i+2]=='U' && s[i+3]=='B') {
                ans[id] = ' ';
                id++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}



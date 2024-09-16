#include<bits/stdc++.h>
using namespace std;

int main()
{
    int flag = 1;
    string s;
    cin >> s;
    for(int i=1;i<s.size();i++) {
        if(s[i] >= 'a' && s[i] <= 'z') flag = 0;
    }
    if(flag == 1) {
        for(int i=1;i<s.size();i++) s[i] += char('a' - 'A');
        if(s[0] >= 'a' && s[0] <= 'z') s[0] += char('A' - 'a');
        else s[0] += char('a' - 'A');
    }
    cout << s << endl;
    return 0;
}



#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s, a = "1111111", b = "0000000";
    int flag = 1;
    cin >> s;
    for(int i=0;i+6<s.size();i++) {
        if(s.substr(i, 7) == a || s.substr(i, 7) == b) {
            cout << "YES" << endl;
            flag = 0;
            break;
        }
    }
    if(flag == 1) cout << "NO" << endl;
    return 0;
}




#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, small = -1;
    string s;
    cin >> n >> s;
    for(int i=1;i<n;i++) {
        if(s[i] < s[i - 1]) {
            small = i - 1;
            break;
        }
    }
    if(small == -1) {
        for(int i=0;i<s.size()-1;i++) cout << s[i];
    }
    else {
        for(int i=0;i<s.size();i++) {
            if(i != small) cout << s[i];
        }
    }
    cout << endl;

    return 0;
}


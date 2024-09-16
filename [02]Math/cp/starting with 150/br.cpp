#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, shift;
    string s;
    cin >> n >> s;
    for(int i=0;i<s.size();i++) {
        shift = (s[i] - 'A' + n) % 26;
        s[i] = char(shift + 'A');
    }
    cout << s << endl;
    return 0;
}


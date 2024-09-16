#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, n;
    string s;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> n >> s;
        if(s == "Alice") {
            if(n % 3 == 1) cout << "Case " << i << ": " << "Bob" << endl;
            else cout << "Case " << i << ": " << "Alice" << endl;
        }
        else {
            if(n % 3) cout << "Case " << i << ": " << "Bob" << endl;
            else cout << "Case " << i << ": " << "Alice" << endl;
        }
    }
    return 0;
}

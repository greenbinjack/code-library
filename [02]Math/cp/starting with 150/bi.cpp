#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, a, b, cnt;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cnt=0;
        cin >> a >> b;
        b++;
        while(b > 0){
            cnt++;
            b /= 10;
        }
        cout << a * (cnt - 1) << endl;
    }
    return 0;
}

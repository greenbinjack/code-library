#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, n, d, flag;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> n >> d;
        flag = 0;
        for(int i=0;i*i<=d;i++){
            if((i + (d+i) / (i+1)) <= n) {
                flag = 1;
                break;
            }
        }
        if(flag == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}




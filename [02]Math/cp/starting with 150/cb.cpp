#include<bits/stdc++.h>
using namespace std;

int main()
{
    int s, cnt = 1, flag = 1;
    cin >> s;
    if(s == 1) cnt = 4;
    else if(s == 2) cnt = 4;
    else{
        while(flag || s != 4) {
            if(s == 4) flag = 0;
            if(s % 2 == 0) s /= 2;
            else s = s * 3 + 1;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}

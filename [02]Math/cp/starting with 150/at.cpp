#include<bits/stdc++.h>
using namespace std;

int lucky_number(int num)
{
    while(num > 0) {
        if((num % 10) != 4 && (num % 10) != 7) return 0;
        num /= 10;
    }
    return 1;
}

int main()
{
    int n, ok = 0;
    cin >> n;
    for(int i=1;i<=n;i++) {
        if(lucky_number(i) == 1 && (n % i == 0)) {
            ok = 1;
            break;
        }
    }
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}


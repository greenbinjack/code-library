#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc, n, k, candy;
    cin >> tc;
    for(int i=1;i<=tc;i++) {
        cin >> n >> k;
        candy = n / k;
        candy = n - candy * k;
        cout << (n / k) * k + min(candy, k/2) << endl;
    }
    return 0;
}




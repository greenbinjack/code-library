#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, p[15], sum = 0;
    cin >> n;
    for(int i=0;i<n;i++) cin >> p[i];
    sort(p, p + n);
    for(int i=0;i<n-1;i++) sum += p[i];
    cout << sum + p[n - 1] / 2 << endl;
    return 0;
}


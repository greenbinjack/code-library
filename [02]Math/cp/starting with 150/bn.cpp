#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum = 0, v[25], c[25];
    cin >> n;
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<n;i++) cin >> c[i];
    for(int i=0;i<n;i++) {
        if(v[i] > c[i]) sum += v[i] - c[i];
    }
    cout << sum << endl;

    return 0;
}
